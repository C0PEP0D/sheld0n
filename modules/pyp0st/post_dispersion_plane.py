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

def fit_func(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def parse():
    parser = argparse.ArgumentParser(description='Computes the average velocity along a specific direction')
    parser.add_argument('normal', nargs='?', type=int, default=0, help='specify the plane normal axis')
    parser.add_argument('--number-average', '-n', nargs='?', type=int, default=30, help='number of time steps for wich average quantities are computed, default: 30')
    return parser.parse_args()

def main(normal, n_average):
    print("INFO: Post processing the dispersion in the plane of normal {normal}.".format(normal=normal), flush=True)
    print("INFO: Reading objects...", flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Done. Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    time_dirs, time_list, time = libpost.get_time()
    time = time[:-1]
    average_time_steps = np.round(np.linspace(0, time.size-1, n_average)).astype(int)
    print("INFO: Done.", flush=True)
    print("INFO: Processing init...", flush=True)
    objects_pos_init = {}
    for name in object_names:
        obj = libpost.get_object(time_dirs[time_list.index(0.0)], name)
        if normal == 0:
            pos_1 = libpost.get_object_properties(obj, ["particle_.*__pos_1"])["value"]
            objects_pos_init[name] = np.empty((pos_1.size, 2))
            objects_pos_init[name][:, 0] = pos_1
            objects_pos_init[name][:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_2"])["value"]
        elif normal == 1:
            pos_2 = libpost.get_object_properties(obj, ["particle_.*__pos_2"])["value"]
            objects_pos_init[name] = np.empty((pos_2.size, 2))
            objects_pos_init[name][:, 0] = pos_2
            objects_pos_init[name][:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_0"])["value"]
        elif normal == 2:
            pos_0 = libpost.get_object_properties(obj, ["particle_.*__pos_0"])["value"]
            objects_pos_init[name] = np.empty((pos_0.size, 2))
            objects_pos_init[name][:, 0] = pos_0
            objects_pos_init[name][:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_1"])["value"]
    print("INFO: Done.", flush=True)
    print("INFO: Processing effective velocity along axis...", flush=True)
    objects_standard_deviation = {}
    for name in object_names:
        print("\tINFO: Processing object {name}...".format(name=name), flush=True)
        objects_standard_deviation[name] = np.empty((average_time_steps.shape[0], 2))
        for index in range(average_time_steps.size):
            t = time[average_time_steps[index]]
            print("\t\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
            # read objects
            obj = libpost.get_object(time_dirs[time_list.index(t)], name)
            # effective velocity
            pos = np.empty(objects_pos_init[name].shape)
            if normal == 0:
                pos[:, 0] = libpost.get_object_properties(obj, ["particle_.*__pos_1"])["value"]
                pos[:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_2"])["value"]
            elif normal == 1:
                pos[:, 0] = libpost.get_object_properties(obj, ["particle_.*__pos_2"])["value"]
                pos[:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_0"])["value"]
            elif normal == 2:
                pos[:, 0] = libpost.get_object_properties(obj, ["particle_.*__pos_0"])["value"]
                pos[:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_1"])["value"]
            objects_standard_deviation[name][index, :] = np.std(pos - objects_pos_init[name], axis=0)
            print("\t\tINFO: Done processing t={t}/{t_f}.".format(t=t, t_f=time[-1]), flush=True)
        print("\tDone processing object {name}.".format(name=name), flush=True)
    print("INFO: Done.", flush=True)
    print("INFO: Saving...", flush=True)
    for name in object_names:
        np.savetxt("{name}__standard_deviation_normal_to_{normal}.csv".format(name=name, normal=normal), objects_standard_deviation[name], delimiter=",", header="time,std_x,std_y")
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.normal, args.number_average)
