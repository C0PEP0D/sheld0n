#!/usr/bin/env python3

# command line program
import argparse
# numpy
import numpy as np
# custom lib
import libpost

BINS_NB = 100

def parse():
    parser = argparse.ArgumentParser(description='Filament post processing')
    parser.add_argument('name', help='specify the filament object name')
    #parser.add_argument('distance', type=float, help='arrival distance to consider')
    parser.add_argument('--distance-number', '-d', nargs='?', type=int, default=30, help='number of time steps to extract distance')
    parser.add_argument('--pdf-number', '-p', nargs='?', type=int, default=5, help='number of time steps to extract distance probability function')
    return parser.parse_args()

#def main(name, distance, distance_n, pdf_n):
def main(name, distance_n, pdf_n):
    print("INFO: Reading time...", flush=True)
    time_dirs, time_list, time = libpost.get_time()
    distance_time_steps = np.round(np.linspace(0, time.size-1, distance_n)).astype(int)
    pdf_time_steps = np.round(np.linspace(0, time.size-1, pdf_n)).astype(int)
    print("INFO: Done.", flush=True)
    # print("INFO: Processing arrival time...", flush=True)
    # arrival_time = []
    # mask = None
    # for t_index in range(time.size):
        # t = time[t_index]
        # print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # # read object
        # obj = libpost.get_object(time_dirs[time_list.index(t)], name)
        # # extract distance
        # objects_distance = libpost.get_object_properties(obj, ["particle_.*__distance"])
        # # computes arrival time
        # ## compute mask
        # if mask is None:
            # mask = objects_distance["value"] < distance
        # else:
            # mask = np.logical_or(mask, objects_distance["value"] < distance)
        # ## append result
        # arrival_number = np.sum(mask)
        # print("\tINFO: Number of arrivals: {}".format(arrival_number), flush=True)
        # if arrival_number > len(arrival_time):
            # arrival_time.extend([t] * (arrival_number - len(arrival_time)))
            # if arrival_number == objects_distance["value"].size:
                # print("\tINFO: All particles arrived.", flush=True)
                # print("\tINFO: Done.", flush=True)
                # break
        # # print
        # print("\tINFO: Done.", flush=True)
    # print("INFO: Done.", flush=True)
    print("INFO: Processing average distance...", flush=True)
    average_distance = np.empty(distance_time_steps.size)
    cli_distance = np.empty(distance_time_steps.size)
    for index in range(distance_time_steps.size):
        t = time[distance_time_steps[index]]
        print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # read object
        obj = libpost.get_object(time_dirs[time_list.index(t)], name)
        # extract distance
        objects_distance = libpost.get_object_properties(obj, ["particle_.*__distance"])
        # computes average distance
        average_distance[index] = np.average(objects_distance["value"])
        cli_distance[index] = 1.96 * np.std(objects_distance["value"]) / np.sqrt(objects_distance["value"].size)
        # print
        print("\tINFO: Done.", flush=True)
    print("INFO: Done.", flush=True)
    # computes average velocity
    print("INFO: Computing average velocity...", flush=True)
    average_effective_velocity = np.empty(distance_time_steps.size)
    average_effective_velocity[0] = 0.0
    average_effective_velocity[1:] = -(average_distance[1:] - average_distance[0]) / time[distance_time_steps][1:]
    cli_effective_velocity = np.empty(distance_time_steps.size)
    cli_effective_velocity[0] = 0.0
    cli_effective_velocity[1:] = cli_distance[1:] / time[distance_time_steps][1:]
    print("INFO: Done.", flush=True)
    # computes pdfs
    print("INFO: Processing pdfs...", flush=True)
    pdfs_header = []
    pdfs = []
    for index in range(pdf_time_steps.size):
        t = time[pdf_time_steps[index]]
        print("\tINFO: Processing t={t}/{t_f}...".format(t=t, t_f=time[-1]), flush=True)
        # read object
        obj = libpost.get_object(time_dirs[time_list.index(t)], name)
        # extract distance
        objects_distance = libpost.get_object_properties(obj, ["particle_.*__distance"])
        # computes average distance
        hist, bins = np.histogram(objects_distance["value"], bins=BINS_NB, density=True)
        bins = 0.5 * (bins[1:] + bins[:-1])
        # append
        pdfs_header.append("distance__t_{t},pdf__t_{t}".format(t=t))
        pdfs += [bins, hist]
        # print
        print("\tINFO: Done.", flush=True)
    print("INFO: Done.", flush=True)
    # save snapshot
    print("INFO: Saving...", flush=True)
    # np.savetxt("{name}__average_arrival_time__distance_{distance}.csv".format(name=name, distance=str(distance).replace(".", "o")), np.column_stack([np.average(arrival_time), 1.96 * np.std(arrival_time) / np.sqrt(len(arrival_time))]), delimiter=",", header="average_arrival_time,95CLI")
    np.savetxt("{name}__average_distance.csv".format(name=name), np.column_stack([time[distance_time_steps], average_distance, cli_distance, average_effective_velocity, cli_effective_velocity]), delimiter=",", header="time,average_distance,95CLI,average_effective_velocity,95CLI")
    np.savetxt("{name}__distance_pdf.csv".format(name=name), np.column_stack(pdfs), delimiter=",", header=",".join(pdfs_header))
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    #main(args.name, args.distance, args.distance_number, args.pdf_number)
    main(args.name, args.distance_number, args.pdf_number)
