#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
# internal modules
import libpost

def parse():
    parser = argparse.ArgumentParser(description='Computes the average velocity along a specific direction')
    parser.add_argument('axis', nargs='?', type=int, default=0, help='specify the axis')
    return parser.parse_args()

def main(axis):
    # get positions
    time = libpost.get_time();
    objects_pos = libpost.get_objects_properties(["pos_{axis}".format(axis=axis)])
    # compute velocity
    objects_velocity = copy.deepcopy(objects_pos)
    for object_name in objects_velocity:
        # value
        objects_velocity[object_name]["value"][0, :] = (objects_velocity[object_name]["value"][0, :] - objects_pos[object_name]["value"][0, :])
        for i in range(1, objects_velocity[object_name]["value"].shape[0]):
            objects_velocity[object_name]["value"][i, :] = (objects_velocity[object_name]["value"][i, :] - objects_pos[object_name]["value"][0, :])/time[i]
        # info
        objects_velocity[object_name]["info"] = [info.replace("pos", "velocity_axis_{axis}".format(axis=axis)) for info in objects_velocity[object_name]["info"]]
    # average velocity and 95CLI
    objects_average_velocity = copy.deepcopy(objects_velocity)
    for object_name in objects_velocity:
        # value
        objects_average_velocity[object_name]["value"] = np.column_stack([np.average(objects_velocity[object_name]["value"], axis=1), 1.96 * np.std(objects_velocity[object_name]["value"], axis=1) / np.sqrt(objects_velocity[object_name]["value"].shape[1])])
        # info
        objects_average_velocity[object_name]["info"] = ["average_velocity_axis_{axis}".format(axis=axis), "95CLI"]
    # save
    libpost.savet(time, objects_average_velocity, "average_velocity_axis_{axis}".format(axis=axis))

    # merge
    reduced_objects = {}
    for object_name in objects_average_velocity:
        reduced_object_name = object_name.split("__")[0]
        if not reduced_object_name in reduced_objects:
            reduced_objects[reduced_object_name] = {}
            reduced_objects[reduced_object_name]["value"] = []
            reduced_objects[reduced_object_name]["info"] = objects_average_velocity[object_name]["info"].copy() + ["us/u_eta"] + ["surftimeconst/t_eta"] + ["reorientationtime/t_eta"] + ["surftimeprefactor"]
        # value
        reduced_objects[reduced_object_name]["value"].append(np.array(list(objects_average_velocity[object_name]["value"][-1, :]) + [libpost.get_property_from_object_name(object_name, "us"), libpost.get_property_from_object_name(object_name, "surftimeconst"), libpost.get_property_from_object_name(object_name, "reorientationtime"), libpost.get_property_from_object_name(object_name, "surftimeprefactor")]))
    for reduced_object_name in reduced_objects:
        reduced_objects[reduced_object_name]["value"] = np.stack(reduced_objects[reduced_object_name]["value"])
    libpost.save(reduced_objects, "merge_average_velocity_axis_{axis}".format(axis=axis))

    # fits
    fits_objects = copy.deepcopy(reduced_objects)
    fits_max_objects = copy.deepcopy(reduced_objects)
    for object_name in fits_objects:
        ## sort
        us_sorted = {}
        for row in reduced_objects[reduced_object_name]["value"]:
            if not (row[2], row[4]) in us_sorted:
                us_sorted[(row[2], row[4])] = [row]
            else:
                us_sorted[(row[2], row[4])].append(row)
        for us, rt in us_sorted:
            us_sorted[(us, rt)] = np.stack(us_sorted[(us, rt)])
        # info
        fits_objects[object_name]["info"] = ["surftimeconst"]
        fits_max_objects[object_name]["info"] = ["us/u_eta", "reorientationtime/t_eta", "max_surftimeconst", "max_average_velocity_axis"]
        # value
        fits_objects[object_name]["value"] = [np.linspace(0.0, 10.0, num=50)]
        fits_max_objects[object_name]["value"] = []
        for us, rt in us_sorted:
            #info
            fits_objects[object_name]["info"] += ["average_velocity_axis_us_{us}_rt_{rt}".format(us=us, rt=rt)]
            # value
            fit = np.polynomial.Chebyshev.fit(us_sorted[(us, rt)][:, 3], us_sorted[(us, rt)][:, 0], deg=5)
            fits_objects[object_name]["value"] += [fit(fits_objects[object_name]["value"][0])]
            # max
            index_max = np.argmax(fits_objects[object_name]["value"][-1])
            fits_max_objects[object_name]["value"] += [[us, rt, fits_objects[object_name]["value"][0][index_max], fits_objects[object_name]["value"][-1][index_max]]]
        fits_objects[object_name]["value"] = np.column_stack(fits_objects[object_name]["value"])
        fits_max_objects[object_name]["value"] = np.stack(fits_max_objects[object_name]["value"])
    # save
    libpost.save(fits_objects, "fits_average_velocity_axis_{axis}".format(axis=axis))
    libpost.save(fits_max_objects, "fits_max_average_velocity_axis_{axis}".format(axis=axis))

    # max
    for reduced_object_name in reduced_objects:
        ## sort
        us_sorted = {}
        for row in reduced_objects[reduced_object_name]["value"]:
            if not (row[2], row[4]) in us_sorted:
                us_sorted[(row[2], row[4])] = [row]
            else:
                us_sorted[(row[2], row[4])].append(row)
        for us, rt in us_sorted:
            us_sorted[(us, rt)] = np.stack(us_sorted[(us, rt)])
            us_sorted[(us, rt)] = us_sorted[(us, rt)][np.argmax(us_sorted[(us, rt)][:, 0]), :]
        # save
        reduced_objects[reduced_object_name]["value"] = []
        for us, rt in us_sorted:
            reduced_objects[reduced_object_name]["value"].append(us_sorted[(us, rt)])
        reduced_objects[reduced_object_name]["value"] = np.stack(reduced_objects[reduced_object_name]["value"])
    libpost.save(reduced_objects, "max_average_velocity_axis_{axis}".format(axis=axis))

if __name__ == '__main__':
    args = parse()
    main(args.axis)
