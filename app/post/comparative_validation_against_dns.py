#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as colors
import matplotlib.cm as cm
import matplotlib.ticker as ticker
from matplotlib import animation
from matplotlib import rcParams
rcParams.update({
    # "text.usetex": True,
    "font.family": "serif",
    # "font.serif": ["Computer Modern Roman"],
    "axes.labelsize": 10,
    "font.size": 10,
    "legend.fontsize": 9,
    "xtick.labelsize": 9,
    "ytick.labelsize": 9,
    "axes.linewidth": 1.0,
    "lines.linewidth": 1.1,
})
import copy
# internal modules
import libpost

# ----------------------------
# DNS
# ----------------------------

# ----------------------------
# Parameters
# ----------------------------
N = 256
L = 2*np.pi
kappa = 1e-3
dt = 0.001
T = 1.0
U = 1.0

init_mu = np.array([np.pi, np.pi])
init_sigma = np.array([
    [5e-1, 0.0],
    [0.0, 5e-3]
])

cmap = colors.LinearSegmentedColormap.from_list("", [(1.0, 1.0, 1.0), (1.0, 0.5, 0.5)])
# norm = colors.Normalize(vmin=0.0, vmax=1.0)
# contourf_levels = np.linspace(0.0, 1.0, 16) 
norm = colors.LogNorm(vmin=1e-4, vmax=1.0)
contourf_levels = np.logspace(-4, 0, 16) 
save_every = 100
fps = 30
writer = animation.FFMpegWriter(fps=fps)

print("INFO: Reading time...", flush=True)

time_dir_array, time_array = libpost.get_time()

t_max = 10.0
n_steps = int(time_array[-1]/dt)

# ----------------------------
# Random phases (updated each T)
# ----------------------------
n_periods = int(np.ceil(t_max / T))
# set randomness
np.random.seed(0)
# compute phases
phi_x_arr = 2 * np.pi * np.random.rand(n_periods+1)
phi_y_arr = 2 * np.pi * np.random.rand(n_periods+1)
# save phases
np.savetxt("phi_x_arr.txt", phi_x_arr.reshape((1, phi_x_arr.size)), delimiter=", ")
np.savetxt("phi_y_arr.txt", phi_y_arr.reshape((1, phi_y_arr.size)), delimiter=", ")

current_period = 0

# Grid
x = np.linspace(0, L, N, endpoint=False)
y = np.linspace(0, L, N, endpoint=False)
X, Y = np.meshgrid(x, y, indexing='ij')

# Wavenumbers
kx = np.fft.fftfreq(N, d=L/(2*np.pi*N))
ky = np.fft.fftfreq(N, d=L/(2*np.pi*N))
KX, KY = np.meshgrid(kx, ky, indexing='ij')
K2 = KX**2 + KY**2

# Initial condition

def gaussian_2d(X, Y, mu, sigma, normalized=False):
    pos = np.dstack((X, Y))
    diff = pos - mu

    inv_sigma = np.linalg.inv(sigma)
    det_sigma = np.linalg.det(sigma)

    exponent = np.einsum('...i,ij,...j', diff, inv_sigma, diff)

    if normalized:
        norm = 1.0 / (2 * np.pi * np.sqrt(det_sigma))
        return norm * np.exp(-0.5 * exponent)
    else:
        return np.exp(-0.5 * exponent)

theta = gaussian_2d(X, Y, init_mu, init_sigma)

# FFT helpers
fft2 = np.fft.fft2
ifft2 = np.fft.ifft2

def velocity_field(t):
    global phi_x, phi_y, current_period

    period = int(t // T)
    
    phi_x = phi_x_arr[period]
    phi_y = phi_y_arr[period]

    if (t/T % 1.0) < 0.5:
        u = U * np.sin(Y + phi_y)
        v = np.zeros_like(Y)
    else:
        u = np.zeros_like(X)
        v = U * np.sin(X + phi_x)

    return u, v

def diffusion_step(theta_hat, dt):
    return theta_hat * np.exp(-kappa * K2 * dt)

def advection_rhs(theta, t):
    theta_hat = fft2(theta)
    dtheta_dx = np.real(ifft2(1j*KX * theta_hat))
    dtheta_dy = np.real(ifft2(1j*KY * theta_hat))

    u, v = velocity_field(t)
    return -(u*dtheta_dx + v*dtheta_dy)

print("INFO: Reading passive scalar property over time...", flush=True)

passive_scalar_names = []
for equation_name in libpost.get_equation_names():
    if equation_name.startswith("passive_scalar"):
        passive_scalar_names.append(equation_name)

passive_scalar_pos_0_over_time = {}
passive_scalar_pos_1_over_time = {}
passive_scalar_c_over_time = {}
passive_scalar_grid_c_over_time = {}

for passive_scalar_name in passive_scalar_names:
    passive_scalar_pos_0_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_0", time_dir_array)
    passive_scalar_pos_1_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_1", time_dir_array)
    passive_scalar_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, passive_scalar_name + ".*__c", time_dir_array)
    passive_scalar_grid_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, "grid.*__c", time_dir_array)

print("INFO: Starting DNS...")

# ----------------------------
# Plot setup
# ----------------------------

fig, axes = plt.subplots(2, 3, figsize=(15, 8))

dns_ax = axes.flatten()[0]
green_axes = axes.flatten()[1:]

dns_contourf = None
dns_title = dns_ax.set_title("t = 0.0")
dns_ax.set_xlabel("x")
dns_ax.set_ylabel("y")

dns_cbar = fig.colorbar(cm.ScalarMappable(norm=norm, cmap=cmap), ax=dns_ax)
dns_cbar.ax.tick_params(axis='y')
dns_cbar.set_label(r"$c / c_{\mathrm{max}}$")

green_contourf = []
green_title = []
green_cbar = []
for index, passive_scalar_name in enumerate(passive_scalar_names):
    green_contourf.append(None)
    green_title.append(
        green_axes[index].set_title("t = 0.0")
    )
    green_axes[index].set_xlabel("x")
    green_axes[index].set_ylabel("y")
    green_cbar.append(
        fig.colorbar(cm.ScalarMappable(norm=norm, cmap=cmap), ax=green_axes[index])
    )
    green_cbar[index].ax.tick_params(axis='y')
    green_cbar[index].set_label(r"$c / c_{\mathrm{max}}$")

# ----------------------------
# Time stepping
# ----------------------------

t = 0.0
theta_hat = fft2(theta)

error = []
error_filtered = []; filter_threshold = 1e-1
for index, passive_scalar_name in enumerate(passive_scalar_names):
    error.append([])
    error_filtered.append([])

with writer.saving(fig, "comparison_animation.mp4", dpi=150):
    for n in range(n_steps):

        t = n * dt
    
        # Half diffusion
        theta_hat = diffusion_step(theta_hat, dt/2)
        # cutoff (2/3 rule)
        cutoff = N//3
        theta_hat[cutoff:-cutoff, :] = 0
        theta_hat[:, cutoff:-cutoff] = 0

        theta = np.real(ifft2(theta_hat))

        # Advection (RK2)
        k1 = advection_rhs(theta, t)
        k2 = advection_rhs(theta + dt*k1/2, t + dt/2)
        theta = theta + dt*k2

        # # Advection (RK4)
        # k1 = advection_rhs(theta, t)
        # k2 = advection_rhs(theta + dt*k1/2, t + dt/2)
        # k3 = advection_rhs(theta + dt*k2/2, t + dt/2)
        # k4 = advection_rhs(theta + dt*k3, t + dt)
        # theta = theta + dt*(k1 + 2*k2 + 2*k3 + k4)/6

        theta_hat = fft2(theta)

        # Full diffusion
        theta_hat = diffusion_step(theta_hat, dt/2)
        # cutoff (2/3 rule)
        cutoff = N//3
        theta_hat[cutoff:-cutoff, :] = 0
        theta_hat[:, cutoff:-cutoff] = 0

        # ------------------------
        # Plot update
        # ------------------------
        
        if n % save_every == 0:

            print("INFO: ", n, " / ", n_steps)

            # plot dns
        
            if dns_contourf is not None:
                dns_contourf.remove()

            theta = np.real(ifft2(theta_hat))

            dns_contourf = dns_ax.contourf(
                X, Y, theta,
                levels=contourf_levels,
                cmap=cmap,
                norm=norm,
                zorder=0
            )
            dns_title.set_text(f"DNS, t = {t:.2f}")

            # plot green

            time_index = n//save_every

            for index, passive_scalar_name in enumerate(passive_scalar_names):

                if green_contourf[index] is not None:
                    green_contourf[index].remove()

                passive_scalar_grid_c = np.array(passive_scalar_grid_c_over_time[passive_scalar_name][time_index]).reshape((N, N))

                green_contourf[index] = green_axes[index].contourf(
                    X, Y, passive_scalar_grid_c,
                    levels=contourf_levels,
                    cmap=cmap,
                    norm=norm,
                    zorder=0
                )

                split_size = libpost.get_properties_from_string(passive_scalar_name)["SplitSizeFactor"] * np.pi
                
                green_title[index].set_text(r"$\sigma_{\mathrm{max}} = " + str(round(split_size, 4)) + r"$" + f", t = {t:.2f}")

                # error
                            
                error[index].append(np.linalg.norm(passive_scalar_grid_c - theta) / np.linalg.norm(theta))
                mask = theta > filter_threshold
                error_filtered[index].append(np.linalg.norm(passive_scalar_grid_c[mask] - theta[mask]) / np.linalg.norm(theta[mask]))

                print("INFO: " + passive_scalar_name + ", error ", error[index][-1])

            writer.grab_frame()

plt.close(fig)

# plot dns

dns_fig, dns_ax = plt.subplots(figsize=(5, 4))
dns_contourf = dns_ax.contourf(
    X, Y, theta,
    levels=contourf_levels,
    cmap=cmap,
    norm=norm,
    zorder=0
)

dns_ax.set_xlabel("x")
dns_ax.set_ylabel("y")

dns_cbar = fig.colorbar(cm.ScalarMappable(norm=norm, cmap=cmap), ax=dns_ax)
dns_cbar.ax.tick_params(axis='y')
dns_cbar.set_label(r"$c / c_{\mathrm{max}}$")

plt.savefig("random_sine_flow_dns__t_" + str(t).replace(".", "o") + ".pdf")
plt.close(fig)

# plot green

for index, passive_scalar_name in enumerate(passive_scalar_names):

    passive_scalar_grid_c = np.array(passive_scalar_grid_c_over_time[passive_scalar_name][time_index]).reshape((N, N))

    green_fig, green_ax = plt.subplots(figsize=(5, 4))
    green_contourf = green_ax.contourf(
        X, Y, passive_scalar_grid_c,
        levels=contourf_levels,
        cmap=cmap,
        norm=norm,
        zorder=0
    )

    green_ax.set_xlabel("x")
    green_ax.set_ylabel("y")

    green_cbar = fig.colorbar(cm.ScalarMappable(norm=norm, cmap=cmap), ax=green_ax)
    green_cbar.ax.tick_params(axis='y')
    green_cbar.set_label(r"$c / c_{\mathrm{max}}$")

    split_size = libpost.get_properties_from_string(passive_scalar_name)["SplitSizeFactor"] * np.pi

    plt.savefig("random_sine_flow_green_split_size_" + str(round(split_size, 4)).replace(".", "o") + "__t_" + str(t).replace(".", "o") + ".pdf")
    plt.close(fig)

# plot error

colors = [(1.0, 0.5, 0.5), (0.5, 1.0, 0.5), (0.5, 0.5, 1.0), (1.0, 1.0, 0.5), (0.5, 1.0, 1.0), (1.0, 0.5, 1.0)]
markers = ["o", "s", "D", "*", "P", "X"]
fig, ax = plt.subplots(figsize=(5, 4))
for index, passive_scalar_name in enumerate(passive_scalar_names):

    split_size = libpost.get_properties_from_string(passive_scalar_name)["SplitSizeFactor"] * np.pi

    ax.plot(
        time_array[:-1], error[index], marker=markers[index], color=colors[index], label=r"$\sigma_{\mathrm{max}} = " + str(round(split_size, 4)) + r"$", linestyle='none'
    )
ax.legend(loc='upper right', frameon=True)
ax.set_xlabel("t")
ax.set_ylabel(r"$|| c_{\mathrm{Green}} - c_{\mathrm{dns}} || / || c_{\mathrm{dns}} ||$")
ax.set_yscale('log')
plt.savefig("plot_error_f_time.pdf")
plt.close(fig)

# plot error filtered

fig, ax = plt.subplots(figsize=(5, 4))
for index, passive_scalar_name in enumerate(passive_scalar_names):

    split_size = libpost.get_properties_from_string(passive_scalar_name)["SplitSizeFactor"] * np.pi

    ax.plot(
        time_array[:-1], error_filtered[index], marker=markers[index], color=colors[index], label=r"$\sigma_{\mathrm{max}} = " + str(round(split_size, 4)) + r"$", linestyle='none'
    )
ax.legend(loc='upper right', frameon=True)
ax.set_xlabel("t")
ax.set_ylabel(r"$|| c_{\mathrm{Green}}|_{> c_{\mathrm{filter}}} - c_{\mathrm{dns}}|_{> c_{\mathrm{filter}}} || / || c_{\mathrm{dns}}|_{> c_{\mathrm{filter}}} ||$")
ax.set_yscale('log')
plt.savefig("plot_error_filtered_f_time.pdf")
plt.close(fig)

# plot convergence

split_size_array = []
error_array = []
error_filtered_array = []
for index, passive_scalar_name in enumerate(passive_scalar_names):
    split_size_array.append(libpost.get_properties_from_string(passive_scalar_name)["SplitSizeFactor"] * np.pi)
    error_array.append(np.average(error[index]))
    error_filtered_array.append(np.average(error_filtered[index]))

fit_p, fit_log_e = np.polyfit(np.log(split_size_array), np.log(error_array), 1)
fit_e = np.exp(fit_log_e)

fit_p_f, fit_log_e_f = np.polyfit(np.log(split_size_array), np.log(error_filtered_array), 1)
fit_e_f = np.exp(fit_log_e_f)

fit_split_size_array = np.linspace(np.min(split_size_array), np.max(split_size_array), 2)

fit_split_err = fit_e * fit_split_size_array**fit_p
fit_split_err_f = fit_e_f * fit_split_size_array**fit_p_f

fig, ax = plt.subplots(figsize=(5, 4))
ax.plot(
    split_size_array, error_array, marker="o", color=(1.0, 0.5, 0.5), linestyle='none', label=r"$|| c_{\mathrm{Green}} - c_{\mathrm{dns}} || / || c_{\mathrm{dns}} ||$"
)
ax.plot(
    split_size_array, error_filtered_array, marker="s", color=(0.5, 0.5, 1.0), linestyle='none', label=r"$|| c_{\mathrm{Green}}|_{> c_{\mathrm{filter}}} - c_{\mathrm{dns}}|_{> c_{\mathrm{filter}}} || / || c_{\mathrm{dns}}|_{> c_{\mathrm{filter}}} ||$"
)
ax.plot(
    fit_split_size_array, fit_split_err, color=(1.0, 0.5, 0.5), label=r'$p = ' + str(round(fit_p, 4)) + r'$'
)
ax.plot(
    fit_split_size_array, fit_split_err_f, color=(0.5, 0.5, 1.0), label=r'$p = ' + str(round(fit_p_f, 4)) + r'$'
)
ax.legend(loc='upper left', frameon=True)
ax.set_xlabel(r"$\sigma_{\mathrm{max}}$ (axis inverted)")
ax.set_ylabel(r"$|| c_{\mathrm{Green}} - c_{\mathrm{dns}} || / || c_{\mathrm{dns}} ||$")
ax.set_xscale('log')
ax.invert_xaxis()
ax.set_yscale('log')
plt.savefig("plot_error_f_split_size.pdf")
plt.close(fig)
