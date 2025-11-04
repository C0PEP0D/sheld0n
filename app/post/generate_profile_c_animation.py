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

def parse():
    parser = argparse.ArgumentParser(description='Plots profile of concentration.')
    parser.add_argument('--passive-scalar-name', '-n', default="passive_scalar_blobs", help='name of the passive scalar curve')
    parser.add_argument('--begin', '-b', type=int, default=0, help='begin step')
    parser.add_argument('--end', '-d', type=int, default=-1, help='end step')
    return parser.parse_args()

def main(input_begin, input_end):
    passive_scalar_name = args.passive_scalar_name
    # process
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    time_dir_array, time_array = time_dir_array[input_begin:input_end:1], time_array[input_begin:input_end:1]
    print("INFO: Reading equation property over time...", flush=True)
    profile_c_x_over_time = libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__x", time_dir_array)
    profile_c_c_over_time = libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__c", time_dir_array)
    # normalizing concentration start
    c_max = np.array([x for c in profile_c_c_over_time for x in c]).max()
    profile_c_c_over_time = [np.array(c)/c_max for c in profile_c_c_over_time]
    # normalizing concentration end
    print("INFO: Animating basic...", flush=True)
    art_fig, art_ax = plt.subplots()
    art_ax.set_xlabel(r'$x$')
    art_ax.set_ylabel(r'$c / c_{\mathrm{max}}$')
    artists = []
    for time_index, time in enumerate(time_array):
        artists.append([])
        if profile_c_x_over_time[time_index].size > 0:
            arts = art_ax.plot(profile_c_x_over_time[time_index], profile_c_c_over_time[time_index], marker="o", color=[1.0, 0.5, 0.5])
            artists[-1] += arts
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
        artists.append([])
        if profile_c_x_over_time[time_index].size > 0:
            arts = art_ax.plot(profile_c_x_over_time[time_index], profile_c_c_over_time[time_index], marker="o", color=[1.0, 0.5, 0.5])
            artists[-1] += arts
    # anim
    anim = animation.ArtistAnimation(art_fig, artists, interval=33)
    anim.save("profile_c_animation_log_scale.mp4")

if __name__ == '__main__':
    args = parse()
    main(args.begin, args.end)
