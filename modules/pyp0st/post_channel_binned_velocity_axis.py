#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
import scipy as sp
import scipy.optimize
# internal modules
import libpost

BIN_RANGE = (-1.0, 1.0)
BIN_NB = 20
BINS = np.logspace(-4.0, 0.0, num=BIN_NB+1)

def parse():
    parser = argparse.ArgumentParser(description='Computes particle concentration along an axis')
    parser.add_argument('axis', nargs='?', type=int, default=0, help='specify the axis to process')
    parser.add_argument('-n', '--negative', action='store_true', help='consider axis as negative')
    return parser.parse_args()

def fit_func(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def main(axis, negative):
    print("INFO: Post processing the effective velocity of lagrangian objects along the axis {axis}.".format(axis=axis), flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    time = libpost.get_time()
    print("INFO: Done.", flush=True)
    print("INFO: Reading objects properties...", flush=True)
    objects_pos_vertical = libpost.get_objects_properties(["pos_1"], object_names)
    objects_pos_axis = libpost.get_objects_properties(["pos_{axis}".format(axis=axis)], object_names)
    print("INFO: Done.", flush=True)
    print("INFO: Computing binned velocity...", flush=True)
    objects_velocity_axis = {object_name:{"value":np.empty((BIN_NB, 3)), "info":["pos_1", "velocity_{axis}".format(axis=axis), "95CLI"]} for object_name in objects_pos_axis}
    for object_name in objects_velocity_axis:
        mod_pos_value = np.remainder(1.0 + objects_pos_vertical[object_name]["value"], 2.0) - 1.0
        # symmetry
        mask = (mod_pos_value > 0.0)
        mod_pos_value[mask] = -mod_pos_value[mask]
        mod_pos_value += 1.0
        # compute velocity
        if negative:
            velocity_axis_value = -(np.diff(objects_pos_axis[object_name]["value"], axis=0).transpose() / np.diff(time)).transpose()
        else:
            velocity_axis_value = (np.diff(objects_pos_axis[object_name]["value"], axis=0).transpose() / np.diff(time)).transpose()
        for i in range(BIN_NB):
            y_min = BINS[i]
            y_max = BINS[i+1]
            objects_velocity_axis[object_name]["value"][i, 0] = 0.5 * (y_min + y_max)
            objects_velocity_axis[object_name]["value"][i, 1] = np.average(velocity_axis_value[np.logical_and(mod_pos_value[:-1, :] > y_min, mod_pos_value[:-1, :] < y_max)])
            objects_velocity_axis[object_name]["value"][i, 2] = 1.96 * np.std(velocity_axis_value[np.logical_and(mod_pos_value[:-1, :] > y_min, mod_pos_value[:-1, :] < y_max)]) / np.sqrt(velocity_axis_value.size)
    print("INFO: Done.", flush=True)
    print("INFO: Saving...", flush=True)
    libpost.save(objects_velocity_axis, "binned_velocity_axis_{axis}".format(axis=axis))
    print("INFO: Done.", flush=True)
    
if __name__ == '__main__':
    args = parse()
    main(args.axis, args.negative)
