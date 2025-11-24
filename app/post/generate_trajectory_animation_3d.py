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
# copy
import copy

# parameters

default_equation_list = []
default_color_list = []
default_begin = 0
default_end = -1
default_step = 1
default_xlim = []
default_ylim = []

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=default_equation_list, help='equations for which to plot trajectories')
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
    # process
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    time_dir_array, time_array = time_dir_array[args.begin:args.end:args.step], time_array[args.begin:args.end:args.step]
    print("INFO: Reading equation property over time...", flush=True)
    pos_0_over_time = {}
    pos_1_over_time = {}
    pos_2_over_time = {}
    vorticity_over_time = {}
    for equation_name in equation_name_list:
        pos_0_over_time[equation_name] = libpost.get_equation_property_over_time(equation_name, ".*__pos_0", time_dir_array)
        pos_1_over_time[equation_name] = libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array)
        pos_2_over_time[equation_name] = libpost.get_equation_property_over_time(equation_name, ".*__pos_2", time_dir_array)
    print("INFO: Animating...", flush=True)
    # create figure
    art_fig = plt.figure()
    art_ax = art_fig.add_subplot(projection='3d')
    art_ax.set_xlabel(r'$x$', color='white')
    art_ax.set_ylabel(r'$y$', color='white')
    art_ax.set_zlabel(r"$z$", color='white')
    # set colors
    art_ax.set_facecolor("black")
    art_ax.xaxis.set_pane_color("black")
    art_ax.yaxis.set_pane_color("black")
    art_ax.zaxis.set_pane_color("black")
    art_fig.set_facecolor("black")
    art_ax.spines["bottom"].set_color("white")
    art_ax.spines["top"].set_color("white")
    art_ax.spines["left"].set_color("white")
    art_ax.spines["right"].set_color("white")
    art_ax.xaxis.label.set_color('white')
    art_ax.yaxis.label.set_color('white')
    art_ax.zaxis.label.set_color('white')
    art_ax.tick_params(axis='x', colors='white')
    art_ax.tick_params(axis='y', colors='white')
    art_ax.tick_params(axis='z', colors='white')
    art_ax.grid(which='major', color='gray')
    art_ax.grid(which='minor', color='gray')
    # set axis limits
    if args.xlim:
        art_ax.set_xlim(args.xlim[0], args.xlim[1])
    if args.ylim:
        art_ax.set_ylim(args.ylim[0], args.ylim[1])
    # plot the data
    print("INFO: Plotting...", flush=True)
    trajectories = {}
    artists = []
    legend_handles = []
    for time_index, time in enumerate(time_array):
        artists.append([])
        legend_handles.clear()
        for equation_index, equation_name in enumerate(equation_name_list):
            art = art_ax.scatter(np.concatenate(pos_0_over_time[equation_name][max(0, time_index-16):time_index+1]), np.concatenate(pos_1_over_time[equation_name][max(0, time_index-16):time_index+1]), np.concatenate(pos_2_over_time[equation_name][max(0, time_index-16):time_index+1]), s=2, color=color_list[equation_index % len(color_list)], alpha=0.25)
            artists[-1].append(art)
            art = art_ax.scatter(pos_0_over_time[equation_name][time_index], pos_1_over_time[equation_name][time_index], pos_2_over_time[equation_name][time_index], s=12, color=color_list[equation_index % len(color_list)], label=equation_name)
            artists[-1].append(art)
            legend_handles.append(art)
    # adjust the axis
    art_ax.set_aspect('equal', adjustable='box')
    art_ax.legend(handles=legend_handles, loc='upper right', labelcolor='white', facecolor='black', edgecolor='black')
    # start animating
    print("INFO: Animating and Saving...", flush=True)
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("trajectory_animation.mp4")

if __name__ == '__main__':
    main()
