#!/usr/bin/env python3

# command line program
import argparse
import os
import sys
# numpy
import numpy as np
# internal modules
import libpost
# plotting
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import matplotlib.colors as colors
import matplotlib.cm as cm
# copy
import copy

# parameters

default_passive_scalar_list = ["passive_scalar_blobs"]
default_background_particles_list = ["passive_particles"]
default_color_list = []
default_begin = 0
default_end = -1
default_step = 1
default_xlim = []
default_ylim = []

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D scalar concentration as a scatter plot.')
    parser.add_argument('--passive-scalar-list', '-n', nargs='*', default=default_passive_scalar_list, help='list of the passive scalars')
    parser.add_argument('--background-particles-list', '-p', nargs='*', default=default_background_particles_list, help='list of the particles to be displayed in the background')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
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
    equation_name_list = [tmp for tmp in args.background_particles_list if tmp in equation_names]
    # colors
    if args.color_list:
        color_list = args.color_list
    else:
        cmap_background = plt.get_cmap("rainbow", len(equation_name_list))
        color_list = [cmap_background(index) for index in range(len(equation_name_list))]
    cmap = colors.LinearSegmentedColormap.from_list("", [(0.0, 0.0, 0.0), (1.0, 0.5, 0.5)])
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
    c_min = 1.0
    c_max = 0.0
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_pos_0_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_0", time_dir_array)
        passive_scalar_pos_1_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, ".*__pos_1", time_dir_array)
        passive_scalar_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, passive_scalar_name + "__.*__c", time_dir_array)
        # c_max, c_min
        c_max = max(c_max, np.array([x for c in passive_scalar_c_over_time[passive_scalar_name] for x in c]).max())
        c_min = min(c_min, np.array([x for c in passive_scalar_c_over_time[passive_scalar_name] for x in c if x > 0.0]).min())
    # normalize
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_c_over_time[passive_scalar_name] = [np.array(c)/c_max for c in passive_scalar_c_over_time[passive_scalar_name]]
    c_min /= c_max
    print("INFO: Animating basic...", flush=True)
    art_fig, art_ax = plt.subplots()
    art_ax.set_aspect('equal', 'box')
    # art_ax.grid(False)
    # art_ax.axis('off')
    art_ax.set_facecolor("black")
    art_fig.set_facecolor("black")
    art_ax.spines["bottom"].set_color("white")
    art_ax.spines["top"].set_color("white")
    art_ax.spines["left"].set_color("white")
    art_ax.spines["right"].set_color("white")
    art_ax.xaxis.label.set_color('white')
    art_ax.yaxis.label.set_color('white')
    art_ax.tick_params(axis='x', colors='white')
    art_ax.tick_params(axis='y', colors='white')
    art_ax.grid(which='major', color='gray')
    art_ax.grid(which='minor', color='gray')
    if args.xlim:
        art_ax.set_xlim(args.xlim[0], args.xlim[1])
    if args.ylim:
        art_ax.set_ylim(args.ylim[0], args.ylim[1])
    trajectories = {}
    artists = []
    for time_index, time in enumerate(time_array):
        artists.append([])
        # trajectories
        for equation_index, equation_name in enumerate(equation_name_list):
            art = art_ax.scatter(np.concatenate(pos_0_over_time[equation_name][max(0, time_index-16):time_index+1]), np.concatenate(pos_1_over_time[equation_name][max(0, time_index-16):time_index+1]), s=2, color=color_list[equation_index % len(color_list)], alpha=0.25)
            artists[-1].append(art)
            art = art_ax.scatter(pos_0_over_time[equation_name][time_index], pos_1_over_time[equation_name][time_index], s=12, color=color_list[equation_index % len(color_list)])
            artists[-1].append(art)
        # passive scalar
        for passive_scalar_index, passive_scalar_name in enumerate(passive_scalar_list):
            art = art_ax.scatter(passive_scalar_pos_0_over_time[passive_scalar_name][time_index], passive_scalar_pos_1_over_time[passive_scalar_name][time_index], c=passive_scalar_c_over_time[passive_scalar_name][time_index], cmap=cmap, norm=colors.Normalize(vmin=c_min, vmax=1.0))
            artists[-1].append(art)
    # legend
    min_0 = min([np.concatenate(pos_0_over_time[equation_name]).min() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_0_over_time[passive_scalar_name]).min() for equation in passive_scalar_list])
    max_0 = max([np.concatenate(pos_0_over_time[equation_name]).max() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_0_over_time[passive_scalar_name]).max() for equation in passive_scalar_list])
    min_1 = min([np.concatenate(pos_1_over_time[equation_name]).min() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_1_over_time[passive_scalar_name]).min() for equation in passive_scalar_list])
    max_1 = max([np.concatenate(pos_1_over_time[equation_name]).max() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_1_over_time[passive_scalar_name]).max() for equation in passive_scalar_list])
    for equation_index, equation_name in enumerate(equation_name_list):
        art_ax.text(
            max_0,
            max_1 - equation_index * (max_1 - min_1) / (len(equation_name_list) - 1),
            equation_name, 
            fontsize=8,
            #color=color_list[equation_index % len(color_list)],
            backgroundcolor=color_list[equation_index % len(color_list)]
        )
    # color bar
    cbar = art_fig.colorbar(cm.ScalarMappable(norm=colors.Normalize(vmin=c_min, vmax=1.0), cmap=cmap), ax=art_ax)
    # cbar.outline.set_color('white')
    cbar.ax.tick_params(axis='y', colors='white')
    cbar.ax.set_yticklabels(cbar.ax.get_yticklabels(), color='white')
    cbar.set_label(r"$c / c_{\mathrm{max}}$", color='white')
    # anim
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("scalar_concentration_animation.mp4")

    print("INFO: Animating log scale...", flush=True)
    art_fig, art_ax = plt.subplots()
    art_ax.set_aspect('equal', 'box')
    # art_ax.grid(False)
    # art_ax.axis('off')
    art_ax.set_facecolor("black")
    art_fig.set_facecolor("black")
    art_ax.spines["bottom"].set_color("white")
    art_ax.spines["top"].set_color("white")
    art_ax.spines["left"].set_color("white")
    art_ax.spines["right"].set_color("white")
    art_ax.xaxis.label.set_color('white')
    art_ax.yaxis.label.set_color('white')
    art_ax.tick_params(axis='x', colors='white')
    art_ax.tick_params(axis='y', colors='white')
    art_ax.grid(which='major', color='gray')
    art_ax.grid(which='minor', color='gray')
    if args.xlim:
        art_ax.set_xlim(args.xlim[0], args.xlim[1])
    if args.ylim:
        art_ax.set_ylim(args.ylim[0], args.ylim[1])
    trajectories = {}
    artists = []
    for time_index, time in enumerate(time_array):
        artists.append([])
        # trajectories
        for equation_index, equation_name in enumerate(equation_name_list):
            art = art_ax.scatter(np.concatenate(pos_0_over_time[equation_name][max(0, time_index-16):time_index+1]), np.concatenate(pos_1_over_time[equation_name][max(0, time_index-16):time_index+1]), s=2, color=color_list[equation_index % len(color_list)], alpha=0.25)
            artists[-1].append(art)
            art = art_ax.scatter(pos_0_over_time[equation_name][time_index], pos_1_over_time[equation_name][time_index], s=12, color=color_list[equation_index % len(color_list)])
            artists[-1].append(art)
        # passive scalar
        for passive_scalar_index, passive_scalar_name in enumerate(passive_scalar_list):
            art = art_ax.scatter(passive_scalar_pos_0_over_time[passive_scalar_name][time_index], passive_scalar_pos_1_over_time[passive_scalar_name][time_index], c=passive_scalar_c_over_time[passive_scalar_name][time_index], cmap=cmap, norm=colors.LogNorm(vmin=c_min, vmax=1.0))
            artists[-1].append(art)
    # legend
    min_0 = min([np.concatenate(pos_0_over_time[equation_name]).min() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_0_over_time[passive_scalar_name]).min() for equation in passive_scalar_list])
    max_0 = max([np.concatenate(pos_0_over_time[equation_name]).max() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_0_over_time[passive_scalar_name]).max() for equation in passive_scalar_list])
    min_1 = min([np.concatenate(pos_1_over_time[equation_name]).min() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_1_over_time[passive_scalar_name]).min() for equation in passive_scalar_list])
    max_1 = max([np.concatenate(pos_1_over_time[equation_name]).max() for equation in equation_name_list] + [np.concatenate(passive_scalar_pos_1_over_time[passive_scalar_name]).max() for equation in passive_scalar_list])
    for equation_index, equation_name in enumerate(equation_name_list):
        art_ax.text(
            max_0,
            max_1 - equation_index * (max_1 - min_1) / (len(equation_name_list) - 1),
            equation_name, 
            fontsize=8,
            #color=color_list[equation_index % len(color_list)],
            backgroundcolor=color_list[equation_index % len(color_list)]
        )
    # color bar
    cbar = art_fig.colorbar(cm.ScalarMappable(norm=colors.LogNorm(vmin=c_min, vmax=1.0), cmap=cmap), ax=art_ax)
    # cbar.outline.set_color('white')
    cbar.ax.tick_params(axis='y', colors='white')
    cbar.ax.set_yticklabels(cbar.ax.get_yticklabels(), color='white')
    cbar.set_label(r"$c / c_{\mathrm{max}}$", color='white')
    # anim
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("scalar_concentration_animation_log_scale.mp4")

if __name__ == '__main__':
    main()
