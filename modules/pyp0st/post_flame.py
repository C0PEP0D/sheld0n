#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
# glob
import glob
# regular expression
import re

def parse():
    parser = argparse.ArgumentParser(description='Flame post processing')
    parser.add_argument('name', help='specify the flame object name')
    parser.add_argument('timestep', type=int, help='specify the time step to post process')
    return parser.parse_args()

def get_file_header(file_name):
    head_str = ""
    with open(file_name) as f:
        head_str = f.readline()
    head_str = head_str.replace("#", "")
    head_str = head_str.replace(" ", "")
    head_str = head_str.replace("\n", "")
    head = head_str.split(",")
    return head

def get_time():
    time_dirs = glob.glob("time/*")
    time_list = [float(s.split("/")[1]) for s in glob.glob("time/*")]
    time_list_copy = time_list.copy()
    time_list_copy.sort()
    return time_dirs, time_list, np.array(time_list_copy)

def get_object(time_dir, object_name):
    object_filename = time_dir + "/" + object_name + ".csv"
    return {"info":get_file_header(object_filename), "value":np.loadtxt(object_filename, delimiter=",")}

def get_object_properties(obj, properties):
    regex = ""
    for prop in properties:
        regex += "_{prop}$|".format(prop=prop)
    regex = regex[:-1]
    # extract indexs
    indexs = [index for index, name in enumerate(obj["info"]) if re.search(regex, name)]
    # return
    return {"info":[obj["info"][i] for i in indexs], "value":obj["value"][indexs]}

def main(name, timestep):
    time_dirs, time_list, time = get_time()
    mobject = get_object(time_dirs[time_list.index(time[timestep])], name)
    # # get positions
    objects_pos_0 = get_object_properties(mobject, ["s_.*__pos_0"])
    objects_pos_1 = get_object_properties(mobject, ["s_.*__pos_1"])
    objects_pos_2 = get_object_properties(mobject, ["s_.*__pos_2"])
    # sort stuff based on s
    # result = {}
    # for object_name in objects_pos:
        # for i in range(len(objects_pos[object_name]["info"])):
            # s = libpost.get_property_from_object_name(objects_pos[object_name]["info"][i], "s")
            # if s in result:
                # result[s].append({"info":objects_pos[object_name]["info"][i], "value":objects_pos[object_name]["value"][:, i]})
            # else:
                # result[s] = [{"info":objects_pos[object_name]["info"][i], "value":objects_pos[object_name]["value"][:, i]}]
    # # extract snapshot
    # for snapshot_id in range(len(time)):
        # snapshot = []
        # for s, data in result.items():
            # snapshot.append([s] +  [d["value"][snapshot_id] for d in data])
    # save snapshot
    np.savetxt("{name}__t_{time}.csv".format(name=name, time=str(time[timestep]).replace(".", "o")), np.column_stack((objects_pos_0["value"], objects_pos_1["value"], objects_pos_2["value"])), delimiter=",", header="pos_0,pos_1,pos_2")

if __name__ == '__main__':
    args = parse()
    main(args.name, args.timestep)
