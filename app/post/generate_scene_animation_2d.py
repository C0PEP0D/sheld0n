#!/usr/bin/env python3

# command line program
import argparse
import os
import sys
# numpy
import numpy as np
# internal modules
import libpost
# copy
import copy
# plotting
import matplotlib;
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.collections as collections
import matplotlib.colors as colors
import matplotlib.cm as cm
import matplotlib.ticker as ticker
import matplotlib.animation as animation
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

# parameters

default_passive_scalar_list = ["passive_scalar_blobs"]
default_equation_list = ["passive_particles", "odor_trackers_gradient", "odor_emitters"]
default_color_list = [(0.75, 0.75, 0.75), (0.5, 0.5, 1.0), (1.0, 0.5, 0.5)]
default_cmap_color_list = [(1.0, 0.5, 0.5), (0.5, 1.0, 0.5), (0.5, 0.5, 1.0)]
default_begin = 0
default_end = -1
default_step = 1
default_xlim = []
default_ylim = []

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=default_equation_list, help='equations for which to plot trajectories')
    parser.add_argument('--passive-scalar-list', '-p', nargs='*', default=default_passive_scalar_list, help='passive scalars for which to plot the concentration')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
    parser.add_argument('--cmap-color-list', '-m', nargs='*', default=default_cmap_color_list, help='color for each passive scalar')
    parser.add_argument('--begin', '-b', type=int, default=default_begin, help='begin step')
    parser.add_argument('--end', '-d', type=int, default=default_end, help='end step')
    parser.add_argument('--step', '-s', type=int, default=default_step, help='animation frame step')
    parser.add_argument('--xlim', '-x', type=float, nargs=2, default=default_xlim, help='axis x lim')
    parser.add_argument('--ylim', '-y', type=float, nargs=2, default=default_ylim, help='axis y lim')
    return parser.parse_args()

# INFO : UNCOMENT THE FOLLOWING IF YOU WANT TO USE THE CUSTOMIZATION GUI OF THE SCRIPT
# from gooey import Gooey
# @Gooey(
#     show_success_modal=False,
#     show_restart_button=False
# )
def main():
    args = parse()
    print("INFO: Reading equation names...", flush=True)
    equation_names = libpost.get_equation_names()
    print("INFO: Ubpdating equation lists...", flush=True)
    passive_scalar_list = [tmp for tmp in args.passive_scalar_list if tmp in equation_names]
    equation_name_list = [tmp for tmp in args.equation_list if tmp in equation_names]
    # equations
    if not equation_name_list:
        equation_name_list = equation_names
    # colors
    if args.color_list:
        color_list = args.color_list
    else:
        cmap = plt.get_cmap("rainbow", len(equation_name_list))
        color_list = [cmap(index) for index in range(len(equation_name_list))]
    cmap = [colors.LinearSegmentedColormap.from_list("", [(1.0, 1.0, 1.0), args.cmap_color_list[index]]) for index in range(len(args.cmap_color_list))]
    # process
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    time_dir_array, time_array = time_dir_array[args.begin:args.end:args.step], time_array[args.begin:args.end:args.step]
    print("INFO: Reading equation property over time...", flush=True)
    pos_0_over_time = {}
    pos_1_over_time = {}
    for equation_name in equation_name_list:
        pos_0_over_time[equation_name] = libpost.get_equation_property_over_time(equation_name, ".*__pos_0", time_dir_array)
        pos_1_over_time[equation_name] = libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array)
    print("INFO: Reading passive scalar property over time...", flush=True)
    passive_scalar_pos_0_over_time = {}
    passive_scalar_pos_1_over_time = {}
    passive_scalar_c_over_time = {}
    passive_scalar_grid_c_over_time = {}
    c_max = 0.0
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_pos_0_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_0", time_dir_array)
        passive_scalar_pos_1_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_1", time_dir_array)
        passive_scalar_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, passive_scalar_name + ".*__c", time_dir_array)
        # c_max
        c = [_c for cc in passive_scalar_c_over_time[passive_scalar_name] for _c in cc if _c > 0.0]
        c_max = max(c_max, np.array(c).max())
        # grid
        passive_scalar_grid_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, "grid.*__c", time_dir_array)



    
    print("INFO: Start...", flush=True)
    # create figure
    art_fig, art_ax = plt.subplots()
    art_ax.set_aspect('equal', 'box')
    art_ax.set_xlabel(r'$x$')
    art_ax.set_ylabel(r'$y$')
    # set limits
    if args.xlim:
        art_ax.set_xlim(args.xlim[0], args.xlim[1])
    else:
        xs = []
        # passive scalars
        for name in passive_scalar_list:
            for t in range(len(time_array)):
                xs += passive_scalar_pos_0_over_time[name][t].tolist()
        
        # trajectories
        for name in equation_name_list:
            for t in range(len(time_array)):
                xs += pos_0_over_time[name][t].tolist()
        # set
        art_ax.set_xlim(np.min(xs), np.max(xs))
    if args.ylim:
        art_ax.set_ylim(args.ylim[0], args.ylim[1])
    else:
        ys = []
        # passive scalars
        for name in passive_scalar_list:
            for t in range(len(time_array)):
                ys += passive_scalar_pos_1_over_time[name][t].tolist()
        
        # trajectories
        for name in equation_name_list:
            for t in range(len(time_array)):
                ys += pos_1_over_time[name][t].tolist()
        # set
        art_ax.set_ylim(np.min(ys), np.max(ys))
    # layout
    art_fig.tight_layout()
    # initialize plots
    print("INFO: Plotting...", flush=True)
    # passive scalar
    nx, ny = 256, 256
    x = np.linspace(0.0, 2.0 * np.pi, nx, endpoint=False)
    y = np.linspace(0.0, 2.0 * np.pi, ny, endpoint=False)

    X, Y = np.meshgrid(x, y)
    levels = np.linspace(0.0, 1.0, 16) 
    passive_scalar_contourf = {}
    passive_scalar_cbar = {}
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_contourf[passive_scalar_name] = None
        # cbar
        passive_scalar_cbar[passive_scalar_name] = art_fig.colorbar(cm.ScalarMappable(norm=colors.LogNorm(vmin=1e-4, vmax=1.0), cmap=cmap[passive_scalar_index % len(args.cmap_color_list)]), ax=art_ax)
        passive_scalar_cbar[passive_scalar_name].ax.tick_params(axis='y')
        passive_scalar_cbar[passive_scalar_name].set_label(passive_scalar_name + ": " + r"$c / c_{\mathrm{max}}$")
    # trajectories
    trajectory_scatters = {}
    current_point_scatters = {}
    for equation_index, equation_name in enumerate(equation_name_list):
        trajectory_scatters[equation_name] = art_ax.scatter(
            [], [], s=8, color=color_list[equation_index % len(color_list)], alpha=0.25, linewidth=0.0
        )
        current_point_scatters[equation_name] = art_ax.scatter(
            [], [], s=16, color=color_list[equation_index % len(color_list)], label=equation_name, linewidth=0.0
        )
    # legend
    art_ax.legend(loc='upper right', frameon=True)
    # plot the data
    writer = animation.FFMpegWriter(fps=30)
    with writer.saving(art_fig, "scene_animation.mp4", dpi=150):
        # passive_scalar_collection = None
        for time_index, time in enumerate(time_array):
            # passive scalar size update            
            for passive_scalar_index, passive_scalar_name in enumerate(passive_scalar_list):

                if passive_scalar_contourf[passive_scalar_name] is not None:
                    passive_scalar_contourf[passive_scalar_name].remove()

                passive_scalar_contourf[passive_scalar_name] = art_ax.contourf(
                    X, Y, np.array(passive_scalar_grid_c_over_time[passive_scalar_name][time_index]).reshape((nx, ny)).T,
                    levels=levels,
                    cmap=cmap[passive_scalar_index % len(args.cmap_color_list)],
                    norm=colors.LogNorm(vmin=1e-4, vmax=1.0),
                    zorder=0
                )

            # trajectory update
            for equation_name in equation_name_list:
                traj = trajectory_scatters[equation_name]
                x = np.concatenate(pos_0_over_time[equation_name][max(0, time_index-32):time_index+1])
                y = np.concatenate(pos_1_over_time[equation_name][max(0, time_index-32):time_index+1])
                traj.set_offsets(np.c_[x, y])
            
                cur = current_point_scatters[equation_name]
                cur.set_offsets(np.c_[
                    pos_0_over_time[equation_name][time_index],
                    pos_1_over_time[equation_name][time_index]
                ])
            # animation
            writer.grab_frame()
            # verbose
            if (time_index % (max(len(time_array), 16)//16) ) == 0:
                print("INFO: " + str(time_index) + "/" + str(len(time_array)), flush=True)

if __name__ == '__main__':
    main()
