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
BIN_NB = 'auto'

def parse():
    parser = argparse.ArgumentParser(description='Computes particle concentration along an axis')
    parser.add_argument('nb', nargs='?', type=int, default=4, help='number of times to process')
    return parser.parse_args()

def fit_func(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def main(nb):
    axis = 1
    print("INFO: Post processing the concentration of lagrangian objects along the axis {axis}.".format(axis=axis), flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    time = libpost.get_time()
    print("INFO: Done.", flush=True)
    print("INFO: Reading objects properties...", flush=True)
    objects_pos_axis = libpost.get_objects_properties(["pos_{axis}".format(axis=axis)], object_names)
    print("INFO: Done.", flush=True)
    print("INFO: Computing concentration pdfs...", flush=True)
    objects_concentration_pdfs = {object_name:{"value":None, "info":["concentration".format(axis=axis), "pdf"]} for object_name in objects_pos_axis}
    for i in range(nb):
        index = int(round(float(i / (nb - 1.0)) * (len(time) - 1)))
        for object_name in objects_concentration_pdfs:
            mod_pos_value = np.remainder(1.0 + objects_pos_axis[object_name]["value"][index, :], 2.0) - 1.0
            hist, bin_edges = np.histogram(mod_pos_value, bins=np.histogram_bin_edges(mod_pos_value, bins=BIN_NB, range=BIN_RANGE), range=BIN_RANGE, density=True)
            bins = (bin_edges[1:] + bin_edges[:-1])/2
            # info
            objects_concentration_pdfs[object_name]["value"] = np.column_stack((bins, hist))
        print("INFO: Saving...", flush=True)
        libpost.save(objects_concentration_pdfs, "concentration_axis_{axis}__t_{time}".format(axis=axis, time=str(time[index]).replace(".", "o")))
        print("INFO: Done.", flush=True)
    print("INFO: Done.", flush=True)
    
if __name__ == '__main__':
    args = parse()
    main(args.nb)
