#!/usr/bin/env python3

# command line program
import argparse
import os
import sys
# deepcopy
import copy
# numpy
import numpy as np
# internal modules
import libpost
# plotting
import matplotlib.pyplot as plt

# parameters

default_equation_list = ["reference", "passive_scalar_blobs"]
default_color_list = []

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=default_equation_list, help='equations for which to plot')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
    return parser.parse_args()

# INFO : UNCOMENT THE FOLLOWING IF YOU WANT TO USE THE CUSTOMIZATION GUI OF THE SCRIPT
# from gooey import Gooey
# @Gooey(
#     show_success_modal=False,
#     show_restart_button=False
# )
def main(passive_scalar_list, input_color_list):
    # equations
    print("INFO: Reading equation names...", flush=True)
    equation_names = libpost.get_equation_names()
    print("INFO: Ubpdating equation lists...", flush=True)
    passive_scalar_list = [tmp for tmp in passive_scalar_list if tmp in equation_names]
    # colors
    if input_color_list:
        color_list = input_color_list
    else:
        cmap = plt.get_cmap("rainbow", len(passive_scalar_list))
        color_list = [cmap(index) for index in range(len(passive_scalar_list))]
    # markers
    marker_list = ["o", "^", "s", "P", "*"]
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    print("INFO: Reading equation property over time...", flush=True)
    profile_c_x_over_time = {}
    profile_c_c_over_time = {}
    c_max = 0.0
    for passive_scalar_name in passive_scalar_list:
        profile_c_x_over_time[passive_scalar_name] = np.array(libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__x", time_dir_array))
        profile_c_c_over_time[passive_scalar_name] = np.array(libpost.get_equation_property_over_time(passive_scalar_name, "profile_c__.*__c", time_dir_array))
        # c_max
        c_max = max(c_max, np.array([x for c in np.nan_to_num(profile_c_c_over_time[passive_scalar_name]) for x in c]).max())
    # normalizing by c_max
    for passive_scalar_name in passive_scalar_list:
        profile_c_c_over_time[passive_scalar_name] = [np.array(c)/c_max for c in profile_c_c_over_time[passive_scalar_name]]
    print("INFO: Plotting q over time ...", flush=True)
    for equation_index, equation_name in enumerate(passive_scalar_list):
        q = np.trapz(profile_c_c_over_time[equation_name], profile_c_x_over_time[equation_name])
        plt.plot(time_array, q, color=color_list[equation_index], marker=marker_list[equation_index % len(marker_list)], label=equation_name)
    plt.xlabel('$t$')
    plt.ylabel(r'$q$')
    plt.legend()
    plt.show()
    print("INFO: Plotting mean over time ...", flush=True)
    for equation_index, equation_name in enumerate(passive_scalar_list):
        q = np.trapz(profile_c_c_over_time[equation_name], profile_c_x_over_time[equation_name])
        mean = np.trapz(profile_c_x_over_time[equation_name] * profile_c_c_over_time[equation_name] / q[:, np.newaxis], profile_c_x_over_time[equation_name])
        plt.plot(time_array, mean, color=color_list[equation_index], marker=marker_list[equation_index % len(marker_list)], label=equation_name)
    plt.xlabel('$t$')
    plt.ylabel(r'$\mu$')
    plt.legend()
    plt.show()
    print("INFO: Plotting std over time ...", flush=True)
    for equation_index, equation_name in enumerate(passive_scalar_list):
        q = np.trapz(profile_c_c_over_time[equation_name], profile_c_x_over_time[equation_name])
        mean = np.trapz(profile_c_x_over_time[equation_name] * profile_c_c_over_time[equation_name] / q[:, np.newaxis], profile_c_x_over_time[equation_name])
        std = np.sqrt(np.trapz((profile_c_x_over_time[equation_name] - mean[:, np.newaxis])**2 * profile_c_c_over_time[equation_name] / q[:, np.newaxis], profile_c_x_over_time[equation_name]))
        plt.plot(time_array, std, color=color_list[equation_index], marker=marker_list[equation_index % len(marker_list)], label=equation_name)
    plt.xlabel('$t$')
    plt.ylabel(r'$\sigma$')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    args = parse()
    main(args.equation_list, args.color_list)
