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

default_equation_list = []
default_color_list = []

# core

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=default_equation_list, help='equations for which to plot trajectorys')
    parser.add_argument('--color-list', '-c', nargs='*', default=default_color_list, help='color for each equation')
    return parser.parse_args()

# INFO : UNCOMENT THE FOLLOWING IF YOU WANT TO USE THE CUSTOMIZATION GUI OF THE SCRIPT
# from gooey import Gooey
# @Gooey(
#     show_success_modal=False,
#     show_restart_button=False
# )
def main(input_equation_list, input_color_list):
    # equations
    print("INFO: Reading equation names...", flush=True)
    equation_names = libpost.get_equation_names()
    print("INFO: Ubpdating equation lists...", flush=True)
    equation_name_list = [tmp for tmp in input_equation_list if tmp in equation_names]
    if not equation_name_list:
        equation_name_list = equation_names
    # colors
    if input_color_list:
        color_list = input_color_list
    else:
        cmap = plt.get_cmap("rainbow", len(equation_name_list))
        color_list = [cmap(index) for index in range(len(equation_name_list))]
    # markers
    marker_list = ["o", "^", "s", "P", "*"]
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    print("INFO: Reading equation property over time...", flush=True)
    pos_1_over_time = {}
    for equation_name in equation_name_list:
        pos_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array))
    print("INFO: Plotting average vertical velocity over time ...", flush=True)
    plt.figure(figsize=(3.4, 2.6))
    for equation_index, equation_name in enumerate(equation_name_list):
        plt.scatter(
            time_array[1:], 
            (pos_1_over_time[equation_name] - pos_1_over_time[equation_name][0]).mean(1)[1:] / time_array[1:], 
            color=color_list[equation_index], 
            marker=marker_list[equation_index % len(marker_list)],
            label=equation_name,
        )
    plt.xlabel('$t$')
    plt.ylabel(r'$\langle V_{\mathrm{eff.}} \rangle$')
    plt.legend(frameon=True)
    plt.tight_layout()
    plt.savefig("average_vertical_velocity_over_time.pdf") 

if __name__ == '__main__':
    args = parse()
    main(args.equation_list, args.color_list)
