#!/usr/bin/env python3

# command line program
import argparse
# numpy
import numpy as np
# scipy
import scipy as sp
import scipy.stats
# custom lib
import libpost

BINS_NB = 512
BINS_RANGE = (0.0, 2.0)

def parse():
    parser = argparse.ArgumentParser(description='Tracers post processing')
    parser.add_argument('name', help='specify the object name')
    parser.add_argument('--number-average', '-n', nargs='?', type=int, default=30, help='number of time steps for wich average quantities are computed')
    parser.add_argument('--number-profiles', '-p', nargs='?', type=int, default=5, help='number of time steps for wich profiles are computed')
    return parser.parse_args()

def main(name, n_average, n_profiles):
    print("INFO: Reading time...", flush=True)
    time_dirs, time_list, time = libpost.get_time()
    #time = time[:10]
    average_time_steps = np.round(np.linspace(0, time.size-1, n_average)).astype(int)
    profiles_time_steps = np.round(np.linspace(0, time.size-1, n_profiles)).astype(int)
    print("INFO: Done.", flush=True)
    print("INFO: Processing velocity as function of distance...", flush=True)
    print("\tINFO: Processing init...", flush=True)
    obj = libpost.get_object(time_dirs[time_list.index(0.0)], name)
    objects_pos_0 = libpost.get_object_properties(obj, ["particle_.*__pos_0"])
    objects_pos_1 = libpost.get_object_properties(obj, ["particle_.*__pos_1"])
    objects_pos_2 = libpost.get_object_properties(obj, ["particle_.*__pos_2"])
    objects_pos_init = np.empty((objects_pos_0["value"].size, 3))
    objects_pos_init[:, 0] = objects_pos_0["value"]
    objects_pos_init[:, 1] = objects_pos_1["value"]
    objects_pos_init[:, 2] = objects_pos_2["value"]
    print("\tINFO: Done.", flush=True)
    distance = []
    for index in range(time.size):
        t = time[index]
        print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # read object
        obj = libpost.get_object(time_dirs[time_list.index(t)], name)
        # extract distance
        objects_pos = np.empty((objects_pos_init.shape[0], 3))
        objects_pos[:, 0] = libpost.get_object_properties(obj, ["particle_.*__pos_0"])["value"]
        objects_pos[:, 1] = libpost.get_object_properties(obj, ["particle_.*__pos_1"])["value"]
        objects_pos[:, 2] = libpost.get_object_properties(obj, ["particle_.*__pos_2"])["value"]
        objects_distance = np.linalg.norm(objects_pos - objects_pos_init, axis=1)
        # computes average distance
        distance.append(objects_distance)
        # print
        print("\tINFO: Done.", flush=True)
    distance = np.stack(distance)
    velocity = (np.diff(distance, axis=0).transpose() / np.diff(time)).transpose()
    values, bins, nb = sp.stats.binned_statistic(distance[:-1,:].flatten(), velocity.flatten(), statistic="mean", bins=BINS_NB, range=BINS_RANGE)
    std_values, bins, nb = sp.stats.binned_statistic(distance[:-1,:].flatten(), velocity.flatten(), statistic="std", bins=BINS_NB, range=BINS_RANGE)
    bins = 0.5 * (bins[1:] + bins[:-1])
    np.savetxt("{name}__average_dispersion_velocity.csv".format(name=name), np.column_stack((bins, values, 1.96 * std_values / np.sqrt(np.bincount(nb)))), delimiter=",", header="distance,velocity,95CLI")
    print("INFO: Done.", flush=True)
    # computes pdfs
    print("INFO: Processing pdfs...", flush=True)
    pdfs_header = []
    pdfs = []
    for index in range(profiles_time_steps.size):
        t = time[profiles_time_steps[index]]
        print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # computes distance pdf
        hist, bins = np.histogram(distance, bins=BINS_NB, density=True)
        bins = 0.5 * (bins[1:] + bins[:-1])
        # append
        pdfs_header.append("distance__t_{t},pdf__t_{t}".format(t=t))
        pdfs += [bins, hist]
        # print
        print("\tINFO: Done.", flush=True)
    print("INFO: Done.", flush=True)
    # save snapshot
    print("INFO: Saving...", flush=True)
    np.savetxt("{name}__distance_pdf.csv".format(name=name), np.column_stack(pdfs), delimiter=",", header=",".join(pdfs_header))
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.name, args.number_average, args.number_profiles)
