#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
# internal modules
import libpost

def parse():
    parser = argparse.ArgumentParser(description='Computes various flow statistics')
    parser.add_argument('nu', type=float, help='specify the cinematic viscosity of the flow')
    return parser.parse_args()

def main(nu):
    # input
    mesh = libpost.get_mesh()
    flow_u_0 = libpost.get_flow_properties(["u_0"])
    flow_u_1 = libpost.get_flow_properties(["u_1"])
    flow_u_2 = libpost.get_flow_properties(["u_2"])
    flow_j_0_0 = libpost.get_flow_properties(["j_0_0"])
    flow_j_0_1 = libpost.get_flow_properties(["j_0_1"])
    flow_j_0_2 = libpost.get_flow_properties(["j_0_2"])
    flow_j_1_0 = libpost.get_flow_properties(["j_1_0"])
    flow_j_1_1 = libpost.get_flow_properties(["j_1_1"])
    flow_j_1_2 = libpost.get_flow_properties(["j_1_2"])
    flow_j_2_0 = libpost.get_flow_properties(["j_2_0"])
    flow_j_2_1 = libpost.get_flow_properties(["j_2_1"])
    flow_j_2_2 = libpost.get_flow_properties(["j_2_2"])
    # prop
    nx = int(round((mesh["value"].shape[1]//3)**(1.0/3.0)))
    nt = flow_u_0["value"].shape[0]
    mesh = mesh["value"].reshape((3, nx, nx, nx))
    u_0 = flow_u_0["value"].reshape((nt, nx, nx, nx))
    u_1 = flow_u_1["value"].reshape((nt, nx, nx, nx))
    u_2 = flow_u_2["value"].reshape((nt, nx, nx, nx))
    dx = (mesh[0, 1, 0, 0] - mesh[0, 0, 0, 0])
    # velocities
    u_mean = np.array([np.average(flow_u_0["value"]), np.average(flow_u_1["value"]), np.average(flow_u_2["value"])]) # <- should be 0
    u_rms = (1.0/np.sqrt(3.0)) * np.average(np.sqrt(np.square(flow_u_0["value"] - u_mean[0]) + np.square(flow_u_1["value"] - u_mean[1]) + np.square(flow_u_2["value"] - u_mean[2])))
    # turbulence flow velocity gradients properties
    dissipation_rate = copy.deepcopy(flow_j_0_0)
    stretch = copy.deepcopy(flow_j_0_0)
    rotation = copy.deepcopy(flow_j_0_0)
    for i in range(0, dissipation_rate["value"].shape[0]):
        for j in range(0, dissipation_rate["value"].shape[1]):
            # set J
            J = np.empty((3, 3))
            J[0, 0] = flow_j_0_0["value"][i, j]
            J[0, 1] = flow_j_0_1["value"][i, j]
            J[0, 2] = flow_j_0_2["value"][i, j]
            J[1, 0] = flow_j_1_0["value"][i, j]
            J[1, 1] = flow_j_1_1["value"][i, j]
            J[1, 2] = flow_j_1_2["value"][i, j]
            J[2, 0] = flow_j_2_0["value"][i, j]
            J[2, 1] = flow_j_2_1["value"][i, j]
            J[2, 2] = flow_j_2_2["value"][i, j]
            S = 0.5 * (J + J.transpose())
            O = 0.5 * (J - J.transpose())
            # compute
            dissipation_rate["value"][i, j] = 2.0 * nu * np.sum(np.square(S.flatten()))
            #dissipation_rate["value"][i, j] = 2.0 * nu * np.sum(np.square([O[0, 1], O[0, 2], O[1, 2]]))
            stretch["value"][i, j] = np.sum(np.abs(np.linalg.eigh(S)[0])) / 4.0
            rotation["value"][i, j] = np.linalg.norm(np.array([-O[1, 2], O[0, 2], -O[0, 1]]))
    dissipation_rate = np.average(dissipation_rate["value"])
    stretch = np.average(stretch["value"])
    rotation = np.average(rotation["value"])
    # Taylor Micro. Scale
    taylor_micro_scale = np.sqrt(15 * nu * np.square(u_rms) / dissipation_rate)
    taylor_scale_reynolds = u_rms * taylor_micro_scale / nu
    # Kolmogorov scales
    tau_eta = np.sqrt(nu / dissipation_rate)
    eta = nu**(3.0/4.0) * dissipation_rate**(-1.0/4.0)
    u_eta = eta / tau_eta
    # Integral scales
    k = 2 * np.pi / (dx * nx) * np.linspace(1, int(nx/2 + 1)+1, num=int(nx/2 + 1))
    integral_length_scale = np.pi / (2 * u_rms**2) * np.trapz(0.5 * np.average(np.abs(np.fft.rfft(u_0, axis=1) / u_0.shape[1])**2 + np.abs(np.fft.rfft(u_1, axis=1) / u_1.shape[1])**2 + np.abs(np.fft.rfft(u_2, axis=1) / u_2.shape[1])**2, axis=(0, 2, 3)) / k, x=k)
    large_eddy_turnover_time = integral_length_scale / u_rms
    # output
    np.savetxt("flow_statistics.csv", np.array([u_rms, dissipation_rate, taylor_micro_scale, taylor_scale_reynolds, eta, tau_eta, u_eta, integral_length_scale, large_eddy_turnover_time, stretch, rotation]).reshape(1, 11), header="Root Mean Square Velocity, Turbulence Dissipation Rate, Taylor Micro. Scale, Taylor Scale Reynolds, Kolmogorov Length Scale, Kolmogorov Time Scale, Kolmogorov Velocity Scale, Integral Length Scale, Large Eddy Turnover Time, Stretch (lambda), Rotation (omega)", delimiter=",")

if __name__ == '__main__':
    args = parse()
    main(args.nu)
