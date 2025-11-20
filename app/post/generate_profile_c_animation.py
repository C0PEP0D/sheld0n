#!/usr/bin/env python3

# command line program
import argparse
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

default_passive_scalar_list = ["reference", "passive_scalar_blobs"]
default_color_list = []
default_begin = 0
default_end = -1

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots concentration profile for passive scalar equations.')
    parser.add_argument('--passive-scalar-list', '-n', nargs='*', default=default_passive_scalar_list, help='list of the passive scalars')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
    parser.add_argument('--begin', '-b', type=int, default=default_begin, help='begin step')
    parser.add_argument('--end', '-d', type=int, default=default_end, help='end step')
    return parser.parse_args()

def main(input_begin, input_end):
    print("INFO: Reading equation names...", flush=True)
    equation_names = libpost.get_equation_names()
    print("INFO: Ubpdating equation lists...", flush=True)
    passive_scalar_list = [tmp for tmp in args.passive_scalar_list if tmp in equation_names]
    # colors
    if args.color_list:
        color_list = args.color_list
    else:
        cmap_background = plt.get_cmap("rainbow", len(passive_scalar_list))
        color_list = [cmap_background(index) for index in range(len(passive_scalar_list))]
    marker_list = ["o", "^", "s", "P", "*"]
    # process
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    time_dir_array, time_array = time_dir_array[input_begin:input_end:1], time_array[input_begin:input_end:1]
    print("INFO: Reading equation property over time...", flush=True)
    profile_c_x_over_time = {}
    profile_c_c_over_time = {}
    c_max = 0.0
    for passive_scalar_name in passive_scalar_list:
        profile_c_x_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__x", time_dir_array)
        profile_c_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__c", time_dir_array)
        # c_max
        c_max = max(c_max, np.array([x for c in np.nan_to_num(profile_c_c_over_time[passive_scalar_name]) for x in c]).max())
    # normalizing by c_max
    for passive_scalar_name in passive_scalar_list:
        profile_c_c_over_time[passive_scalar_name] = [np.array(c)/c_max for c in profile_c_c_over_time[passive_scalar_name]]

    print("INFO: Animating basic...", flush=True)
    art_fig, art_ax = plt.subplots()
    art_ax.set_xlabel(r'$x$')
    art_ax.set_ylabel(r'$c / c_{\mathrm{max}}$')
    artists = []
    for time_index, time in enumerate(time_array):
        # init
        artists.append([])
        # passive scalar
        for passive_scalar_index, passive_scalar_name in enumerate(passive_scalar_list):
            if profile_c_x_over_time[passive_scalar_name][time_index].size > 0:
                arts = art_ax.plot(profile_c_x_over_time[passive_scalar_name][time_index], profile_c_c_over_time[passive_scalar_name][time_index], marker=marker_list[passive_scalar_index % len(marker_list)], color=color_list[passive_scalar_index % len(color_list)], label=passive_scalar_name)
                artists[-1] += arts
    # legend
    art_ax.legend(handles=artists[-1], loc='upper right')
    # anim
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("profile_c_animation.mp4")


    print("INFO: Animating log...", flush=True)
    art_fig, art_ax = plt.subplots()
    art_ax.set_yscale('log')
    art_ax.set_xlabel(r'$x$')
    art_ax.set_ylabel(r'$c / c_{\mathrm{max}}$')
    artists = []
    for time_index, time in enumerate(time_array):
        # init
        artists.append([])
        # passive scalar
        for passive_scalar_index, passive_scalar_name in enumerate(passive_scalar_list):
            if profile_c_x_over_time[passive_scalar_name][time_index].size > 0:
                arts = art_ax.plot(profile_c_x_over_time[passive_scalar_name][time_index], profile_c_c_over_time[passive_scalar_name][time_index], marker=marker_list[passive_scalar_index % len(marker_list)], color=color_list[passive_scalar_index % len(color_list)], label=passive_scalar_name)
                artists[-1] += arts
    # legend
    art_ax.legend(handles=artists[-1], loc='upper right')
    # anim
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("profile_c_animation_log_scale.mp4")

if __name__ == '__main__':
    args = parse()
    main(args.begin, args.end)
