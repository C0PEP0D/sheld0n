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

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--equation-list', '-e', nargs='*', default=[], help='equations for which to plot trajectorys')
    parser.add_argument('--color-list', '-c', nargs='*', default=[], help='color for each equation')
    parser.add_argument('--no-venv', '-n', action='store_true', help='runs whithout activating automaticaly the virtual environment')
    return parser.parse_args()

def main(input_equation_list, input_color_list):
    # equations
    if input_equation_list:
        equation_name_list = input_equation_list
    else:
        print("INFO: Reading equation names...", flush=True)
        equation_name_list = libpost.get_equation_names()
    # colors
    if input_color_list:
        color_list = input_color_list
    else:
        cmap = plt.get_cmap("plasma", len(equation_name_list))
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
    for equation_index, equation_name in enumerate(equation_name_list):
        plt.plot(
            time_array[1:], 
            (pos_1_over_time[equation_name] - pos_1_over_time[equation_name][0]).mean(1)[1:] / time_array[1:], 
            color=color_list[equation_index], 
            marker=marker_list[equation_index % len(marker_list)],
            label=equation_name,
        )
    plt.xlabel('$t$')
    plt.ylabel(r'$\langle V_{\mathrm{eff.}} \rangle$')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    args = parse()
    if args.no_venv:
        main(args.equation_list, args.color_list)
    else:
        script_path = __file__
        script_dir = os.path.dirname(script_path)
        script_name = os.path.basename(script_path)
    
        cases_dir = script_dir + "/../.."
    
        os.chdir(script_dir)
        if os.path.exists(cases_dir + "/../../bin/activate"):
            os.system("bash -c 'source {cases_dir}/../../bin/activate && ./{script_name} --no-venv {argv}'".format(cases_dir=cases_dir, script_name=script_name, argv=" ".join(sys.argv[1:])))
        else:
            print("WARNING: Can't find the standard sheld0n virtual environment.")
