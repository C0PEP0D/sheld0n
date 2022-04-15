#!/usr/bin/env python3

# command line program
import argparse
# numpy
import numpy as np
# custom lib
import libpost

def parse():
    parser = argparse.ArgumentParser(description='Filament post processing')
    parser.add_argument('name', help='specify the filament object name')
    parser.add_argument('distance', type=float, help='arrival distance to consider')
    return parser.parse_args()

def main(name, distance):
    print("INFO: Reading time...", flush=True)
    time_dirs, time_list, time = libpost.get_time()
    print("INFO: Done.", flush=True)
    arrival_time = []
    mask = None
    for t in time:
        print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # read object
        obj = libpost.get_object(time_dirs[time_list.index(t)], name)
        # extract distance
        objects_distance = libpost.get_object_properties(obj, ["particle_.*__distance"])
        # compute mask
        if mask is None:
            mask = objects_distance["value"] < distance
        else:
            mask = np.logical_or(mask, objects_distance["value"] < distance)
        # append result
        arrival_number = np.sum(mask)
        print("\tINFO: Number of arrivals: {}".format(arrival_number), flush=True)
        if arrival_number > len(arrival_time):
            arrival_time.extend([t] * (arrival_number - len(arrival_time)))
            if arrival_number == objects_distance["value"].size:
                print("\tINFO: All particles arrived.", flush=True)
                print("\tINFO: Done.", flush=True)
                break
        # print
        print("\tINFO: Done.", flush=True)
    # save snapshot
    print("INFO: Saving...", flush=True)
    np.savetxt("{name}__average_arrival_time__distance_{distance}.csv".format(name=name, distance=str(distance).replace(".", "o")), np.column_stack([np.average(arrival_time), 1.96 * np.std(arrival_time) / np.sqrt(len(arrival_time))]), delimiter=",", header="average_arrival_time,95CLI")
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.name, args.distance)
