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
            reduced_objects[reduced_object_name]["info"] = objects_average_velocity[object_name]["info"].copy() + ["us/u_eta", "surftimeconst/t_eta", "reorientationtime/t_eta", "surftimeprefactor", "proportion", "swimnoise", "dirnoise", "jnoise"]
        # value
        reduced_objects[reduced_object_name]["value"].append(np.array(list(objects_average_velocity[object_name]["value"][-1, :]) + [libpost.get_property_from_object_name(object_name, "us"), libpost.get_property_from_object_name(object_name, "surftimeconst"), libpost.get_property_from_object_name(object_name, "reorientationtime"), libpost.get_property_from_object_name(object_name, "surftimeprefactor"), libpost.get_property_from_object_name(object_name, "proportion"), libpost.get_property_from_object_name(object_name, "swimnoise"), libpost.get_property_from_object_name(object_name, "dirnoise"), libpost.get_property_from_object_name(object_name, "jnoise")]))
    for reduced_object_name in reduced_objects:
        reduced_objects[reduced_object_name]["value"] = np.stack(reduced_objects[reduced_object_name]["value"])
    libpost.save(reduced_objects, "merge_average_velocity_axis_{axis}".format(axis=axis))

    ## fits
    #fits_objects = copy.deepcopy(reduced_objects)
    #fits_max_objects = copy.deepcopy(reduced_objects)
    #for object_name in fits_objects:
    #    ## sort
    #    us_sorted = {}
    #    for row in reduced_objects[reduced_object_name]["value"]:
    #        if not (row[2], row[4], row[7], row[8], row[9]) in us_sorted:
    #            us_sorted[(row[2], row[4], row[7], row[8], row[9])] = [row]
    #        else:
    #            us_sorted[(row[2], row[4], row[7], row[8], row[9])].append(row)
    #    for us, rt, sn, dn, jn in us_sorted:
    #        us_sorted[(us, rt, sn, dn, jn)] = np.stack(us_sorted[(us, rt, sn, dn, jn)])
    #    # info
    #    fits_objects[object_name]["info"] = ["surftimeconst"]
    #    fits_max_objects[object_name]["info"] = ["us/u_eta", "reorientationtime/t_eta", "swimnoise", "dirnoise", "jnoise", "max_surftimeconst", "max_average_velocity_axis"]
    #    # value
    #    fits_objects[object_name]["value"] = [np.linspace(0.0, 8.0, num=50)]
    #    fits_max_objects[object_name]["value"] = []
    #    for us, rt, sn, dn, jn in us_sorted:
    #        #info
    #        fits_objects[object_name]["info"] += ["average_velocity_axis_us_{us}_rt_{rt}_sn_{sn}_dn_{dn}_jn_{jn}".format(us=us, rt=rt, sn=sn, dn=dn, jn=jn)]
    #        # value
    #        fit = np.polynomial.Chebyshev.fit(us_sorted[(us, rt, sn, dn, jn)][:, 3], us_sorted[(us, rt, sn, dn, jn)][:, 0], deg=3)
    #        fits_objects[object_name]["value"] += [fit(fits_objects[object_name]["value"][0])]
    #        # max
    #        index_max = np.argmax(fits_objects[object_name]["value"][-1])
    #        fits_max_objects[object_name]["value"] += [[us, rt, sn, dn, jn, fits_objects[object_name]["value"][0][index_max], fits_objects[object_name]["value"][-1][index_max]]]
    #    fits_objects[object_name]["value"] = np.column_stack(fits_objects[object_name]["value"])
    #    fits_max_objects[object_name]["value"] = np.stack(fits_max_objects[object_name]["value"])
    ## save
    #libpost.save(fits_objects, "fits_average_velocity_axis_{axis}".format(axis=axis))
    #libpost.save(fits_max_objects, "fits_max_average_velocity_axis_{axis}".format(axis=axis))

    ## max
    #for reduced_object_name in reduced_objects:
    #    ## sort
    #    us_sorted = {}
    #    for row in reduced_objects[reduced_object_name]["value"]:
    #        if not (row[2], row[4], row[7], row[8], row[9]) in us_sorted:
    #            us_sorted[(row[2], row[4], row[7], row[8], row[9])] = [row]
    #        else:
    #            us_sorted[(row[2], row[4], row[7], row[8], row[9])].append(row)
    #    for us, rt, sn, dn, jn in us_sorted:
    #        us_sorted[(us, rt, sn, dn, jn)] = np.stack(us_sorted[(us, rt, sn, dn, jn)])
    #        us_sorted[(us, rt, sn, dn, jn)] = us_sorted[(us, rt, sn, dn, jn)][np.argmax(us_sorted[(us, rt, sn, dn, jn)][:, 0]), :]
    #    # save
    #    reduced_objects[reduced_object_name]["value"] = []
    #    for us, rt, sn, dn, jn in us_sorted:
    #        reduced_objects[reduced_object_name]["value"].append(us_sorted[(us, rt, sn, dn, jn)])
    #    reduced_objects[reduced_object_name]["value"] = np.stack(reduced_objects[reduced_object_name]["value"])
    #libpost.save(reduced_objects, "max_average_velocity_axis_{axis}".format(axis=axis))

if __name__ == '__main__':
    args = parse()
    main(args.axis)
