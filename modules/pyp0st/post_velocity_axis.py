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

objects_name_info = ["us/u_eta", "surftimeconst/t_eta", "reorientationtime/t_eta", "surftimeprefactor", "proportion", "swimnoise", "dirnoise", "jnoise", "omegamax * t_eta", "reacttime/t_eta"]
objects_name_properties = ["us", "surftimeconst", "reorientationtime", "surftimeprefactor", "proportion", "swimnoise", "dirnoise", "jnoise", "omegamax", "reacttime"]

# filtering
for prop in ["surftimeconst", "swimnoise", "dirnoise", "jnoise", "omegamax", "reacttime"]:
    i = objects_name_properties.index(prop)
    objects_name_info.pop(i)
    objects_name_properties.pop(i)

sorting_property = "surftimeprefactor"
sorting_index = objects_name_properties.index(sorting_property)
sorting_info = objects_name_info.copy()
sorting_info.pop(sorting_index)

def parse():
    parser = argparse.ArgumentParser(description='Computes the average velocity along a specific direction')
    parser.add_argument('axis', nargs='?', type=int, default=0, help='specify the axis')
    return parser.parse_args()

def fit_func(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def main(axis):
    print("INFO: Post processing the effective velocity of lagrangian objects along the axis {axis}.".format(axis=axis), flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    time = libpost.get_time()
    print("INFO: Done.", flush=True)
    print("INFO: Reading objects properties...", flush=True)
    objects_pos = libpost.get_objects_properties(["pos_{axis}".format(axis=axis)], object_names)
    print("INFO: Done.", flush=True)
    print("INFO: Computing effective velocity...", flush=True)
    objects_average_velocity = {object_name:{"value":np.empty((time.size, 2)), "info":["average_velocity_axis_{axis}".format(axis=axis), "95CLI"]} for object_name in objects_pos}
    for object_name in objects_average_velocity:
        effective_velocity_value = np.empty(objects_pos[object_name]["value"].shape)
        # value
        effective_velocity_value[0, :] = 0.0
        effective_velocity_value[1:, :] = (objects_pos[object_name]["value"][1:, :] - objects_pos[object_name]["value"][0, :]) / time[1:].reshape((time.shape[0]-1, 1))
        # info
        objects_average_velocity[object_name]["value"][:, 0] = np.average(effective_velocity_value, axis=1)
        objects_average_velocity[object_name]["value"][:, 1] = 1.96 * np.std(effective_velocity_value, axis=1) / np.sqrt(effective_velocity_value.shape[1])
    print("INFO: Done.", flush=True)
    # print("INFO: Saving...", flush=True)
    # libpost.savet(time, objects_average_velocity, "average_velocity_axis_{axis}".format(axis=axis))
    # print("INFO: Done.", flush=True)
    print("INFO: Merging objects...", flush=True)
    merged_objects = {}
    for object_name in objects_average_velocity:
        reduced_object_name = object_name.split("__")[0]
        if not reduced_object_name in merged_objects:
            merged_objects[reduced_object_name] = {}
            merged_objects[reduced_object_name]["value"] = []
            merged_objects[reduced_object_name]["info"] = ["average_velocity_axis_{axis}_t_inf".format(axis=axis), "95CLI"] + objects_name_info
        merged_objects[reduced_object_name]["value"].append(
            np.array(
                list(objects_average_velocity[object_name]["value"][-1, :]) + [libpost.get_property_from_object_name(object_name, prop) for prop in objects_name_properties]
            )
        )
    for reduced_object_name in merged_objects:
        merged_objects[reduced_object_name]["value"] = np.stack(merged_objects[reduced_object_name]["value"])
    print("INFO: Done.", flush=True)
    print("INFO: Saving...", flush=True)
    libpost.save(merged_objects, "merge_average_velocity_axis_{axis}".format(axis=axis))
    print("INFO: Done.", flush=True)
    print("INFO: Sorting and fitting...", flush=True)
    max_objects = {}
    fits_objects = {object_name:{} for object_name in merged_objects}
    fits_max_objects = {object_name:{} for object_name in merged_objects}
    for object_name in merged_objects:
        object_sorted = {}
        for row in merged_objects[reduced_object_name]["value"]:
            row_list = row.tolist()[2:]
            row_list.pop(sorting_index)
            row_tuple = tuple(row_list)
            if not row_tuple in object_sorted:
                object_sorted[row_tuple] = [row]
            else:
                object_sorted[row_tuple].append(row)
        for row_tuple in object_sorted:
            object_sorted[row_tuple] = np.stack(object_sorted[row_tuple])
        # max
        max_objects[object_name] = {"value":[], "info":merged_objects[object_name]["info"]}
        for row_tuple in object_sorted:
            max_objects[object_name]["value"].append(object_sorted[row_tuple][np.argmax(object_sorted[row_tuple][:, 0]), :])
        max_objects[object_name]["value"] = np.stack(max_objects[object_name]["value"])
        # info
        fits_objects[object_name]["info"] = [sorting_property, "average_velocity_axis_{axis}_t_inf".format(axis=axis)]
        fits_max_objects[object_name]["info"] = sorting_info + ["max_surftimeconst", "max_average_velocity_axis"]
        # value
        fits_objects[object_name]["value"] = [np.linspace(0.0, 8.0, num=50)]
        fits_max_objects[object_name]["value"] = []
        for row_tuple in object_sorted:
            # value
            fit, cov = sp.optimize.curve_fit(fit_func, object_sorted[row_tuple][:, sorting_index], object_sorted[row_tuple][:, 0])
            fits_objects[object_name]["value"] += [fit_func(fits_objects[object_name]["value"][0], *fit)]
            # max
            index_max = np.argmax(fits_objects[object_name]["value"][-1])
            fits_max_objects[object_name]["value"] += [[*row_tuple, fits_objects[object_name]["value"][0][index_max], fits_objects[object_name]["value"][-1][index_max]]]
        fits_objects[object_name]["value"] = np.column_stack(fits_objects[object_name]["value"])
        fits_max_objects[object_name]["value"] = np.stack(fits_max_objects[object_name]["value"])
    print("INFO: Done.", flush=True)
    # save
    print("INFO: Saving...", flush=True)
    libpost.save(max_objects, "max_average_velocity_axis_{axis}".format(axis=axis))
    libpost.save(fits_objects, "fits_average_velocity_axis_{axis}".format(axis=axis))
    libpost.save(fits_max_objects, "fits_max_average_velocity_axis_{axis}".format(axis=axis))
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.axis)
