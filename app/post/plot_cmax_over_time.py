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

default_equation_list = ["reference", "passive_scalar_blobs"]
default_color_list = []
default_step = 1

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=default_equation_list, help='equations for which to plot')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
    parser.add_argument('--step', '-s', type=int, default=default_step, help='color for each equation')
    return parser.parse_args()

# INFO : UNCOMENT THE FOLLOWING IF YOU WANT TO USE THE CUSTOMIZATION GUI OF THE SCRIPT
# from gooey import Gooey
# @Gooey(
#     show_success_modal=False,
#     show_restart_button=False
# )
def main(passive_scalar_list, input_color_list, step):
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
    passive_scalar_c_over_time = {}
    c_max = 0.0
    c_min = 1.0
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_c_over_time[passive_scalar_name] = libpost.get_equation_property_over_time(passive_scalar_name, passive_scalar_name + ".*__c", time_dir_array)
        # c_max, c_min
        c_max = max(c_max, np.array([x for c in passive_scalar_c_over_time[passive_scalar_name] for x in c if x >= 0.0]).max())
        c_min = min(c_min, np.array([x for c in passive_scalar_c_over_time[passive_scalar_name] for x in c if x >= 0.0]).min())
    # normalize
    for passive_scalar_name in passive_scalar_list:
        passive_scalar_c_over_time[passive_scalar_name] = [np.array(c)/c_max for c in passive_scalar_c_over_time[passive_scalar_name]]
    c_min /= c_max
    print("INFO: Plotting Cmax over time ...", flush=True)
    plt.figure(figsize=(3.4, 2.6))
    for equation_index, equation_name in enumerate(passive_scalar_list):
        c_max = []
        for time_index in range(len(time_array)):
            if len(passive_scalar_c_over_time[equation_name][time_index]) > 0:
                c_max.append(np.array(passive_scalar_c_over_time[equation_name][time_index]).max())
            else:
                c_max.append(0.0)
        plt.scatter(time_array[::step], c_max[::step], color=color_list[equation_index], marker=marker_list[equation_index % len(marker_list)], label=equation_name)
    plt.xlabel('$t$')
    plt.ylabel(r'$C_{\mathrm{max}}$')
    plt.legend(frameon=True)
    plt.tight_layout()
    plt.savefig("c_max_over_time.pdf") 

if __name__ == '__main__':
    args = parse()
    main(args.equation_list, args.color_list, args.step)
