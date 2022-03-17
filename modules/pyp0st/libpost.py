#!/usr/bin/env python3

# TODO: rename into full dis axis

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
    parser = argparse.ArgumentParser(description='Post process library that contains most post processing functions.')
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

def get_object_names():
    object_names = []
    time_dirs = glob.glob("time/*")
    if time_dirs:
        object_paths= glob.glob(time_dirs[0] + "/*")
        for path in object_paths:
            object_names.append(path.split("/")[-1].split(".")[0])
    else:
        raise NameError('No data found')
    return object_names

# def get_file_header(file_name):
    # head_str = ""
    # with open(file_name) as f:
        # head_str = f.readline()
    # head_str = head_str.replace("#", "")
    # head_str = head_str.replace(" ", "")
    # head_str = head_str.replace("\n", "")
    # head = head_str.split(",")
    # return head
# 
# def get_object_names():
    # object_names = []
    # if os.path.exists("objects.csv"):
        # with open("objects.csv") as f:
            # _line = f.readline()[1:].split(",")
            # for _column_name in _line:
                # _found_index = _column_name.find("__particle") # group
                # if _found_index > -1:
                    # _object_name = _column_name[:_found_index]
                    # if not _object_name in object_names:
                        # object_names.append(_object_name)
                # else:
                    # _found_index = _column_name.find("__s") # chain
                    # if _found_index > -1:
                        # _object_name = _column_name[:_found_index]
                        # if not _object_name in object_names:
                            # object_names.append(_object_name)
                    # else: # simple object
                        # object_names.append(_column_name.split("__")[0])
    # else:
        # raise NameError('objects.csv not found')
    # return object_names
# 
# def get_time():
    # header = get_file_header("objects.csv")
    # loaded = np.loadtxt("objects.csv", delimiter=",")
    # return loaded[:, header.index("time")]
# 
# def get_objects(object_names = []):
    # if not object_names:
        # object_names = get_object_names()
    # # load
    # header = get_file_header("objects.csv")
    # loaded = np.loadtxt("objects.csv", delimiter=",")
    # # init
    # objects = {}
    # # compute
    # for object_name in object_names:
        # regex = "^{name}.*".format(name=object_name)
        # indexs = [index for index, name in enumerate(header) if re.search(regex, name)]
        # obj = []
        # for index in indexs:
            # obj.append(loaded[:, index])
        # if len(obj) > 1:
            # objects[object_name] = {"value":np.column_stack(obj), "info":[header[index] for index in indexs]}
        # else:
            # objects[object_name] = {"value":np.array(obj), "info":[header[index] for index in indexs]}
    # return objects
# 
# def get_mesh():
    # # load
    # header = get_file_header("mesh.csv")
    # loaded = np.loadtxt("mesh.csv", delimiter=",")
    # # begin sort
    # dict_loaded = {}
    # for i in range(len(header)):
        # name = header[i]
        # # compute index
        # index = int(name[name.find("index_") + 6:].split("__")[0])
        # # fill dict
        # if index in dict_loaded:
            # dict_loaded[index].append(i)
        # else:
            # dict_loaded[index] = [i]
    # ## construct sorted data
    # sorted_info = []
    # sorted_data = []
    # ## keys
    # keys = list(dict_loaded.keys())
    # keys.sort()
    # ## sort data
    # for index in keys:
        # for i in dict_loaded[index]:
            # sorted_info.append(header[i])
            # if len(loaded.shape) == 2:
                # sorted_data.append(loaded[:, i])
            # elif len(loaded.shape) == 1:
                # sorted_data.append(loaded[i])
    # # end sort
    # return {"value":np.column_stack(sorted_data), "info":sorted_info}
# 
# def get_flow():
    # # load
    # header = get_file_header("flow.csv")
    # loaded = np.loadtxt("flow.csv", delimiter=",")
    # # begin sort
    # dict_loaded = {}
    # for i in range(len(header)):
        # name = header[i]
        # # compute index
        # index = int(name[name.find("index_") + 6:].split("__")[0])
        # # fill dict
        # if index in dict_loaded:
            # dict_loaded[index].append(i)
        # else:
            # dict_loaded[index] = [i]
    # ## construct sorted data
    # sorted_info = []
    # sorted_data = []
    # ## keys
    # keys = list(dict_loaded.keys())
    # keys.sort()
    # ## sort data
    # for index in keys:
        # for i in dict_loaded[index]:
            # sorted_info.append(header[i])
            # if len(loaded.shape) == 2:
                # sorted_data.append(loaded[:, i])
            # elif len(loaded.shape) == 1:
                # sorted_data.append(loaded[i])
    # # end sort
    # return {"value":np.column_stack(sorted_data), "info":sorted_info}
# 
# def get_objects_properties(properties, object_names = []):
    # # objects
    # if not object_names:
        # object_names = get_object_names()
    # objects = get_objects(object_names)
    # # regex
    # regex = ""
    # for prop in properties:
        # regex += "_{prop}$|".format(prop=prop)
    # regex = regex[:-1]
    # # init
    # objects_filtered = {}
    # for object_name in objects:
        # indexs = [index for index, name in enumerate(objects[object_name]["info"]) if re.search(regex, name)]
        # obj = []
        # for index in indexs:
            # obj.append(objects[object_name]["value"][:, index])
        # if obj:
            # objects_filtered[object_name] = {"value":np.column_stack(obj), "info":[objects[object_name]["info"][index] for index in indexs]}
    # return objects_filtered
# 
# def get_mesh_properties(properties):
    # # mesh
    # mesh = get_mesh()
    # # regex
    # regex = ""
    # for prop in properties:
        # regex += "_{prop}$|".format(prop=prop)
    # regex = regex[:-1]
    # # init
    # indexs = [index for index, name in enumerate(mesh["info"]) if re.search(regex, name)]
    # value = []
    # for index in indexs:
        # value.append(mesh["value"][:, index])
    # return {"value":np.column_stack(value), "info":[mesh["info"][index] for index in indexs]}
# 
# def get_flow_properties(properties):
    # # flow
    # flow = get_flow()
    # # regex
    # regex = ""
    # for prop in properties:
        # regex += "_{prop}$|".format(prop=prop)
    # regex = regex[:-1]
    # # init
    # indexs = [index for index, name in enumerate(flow["info"]) if re.search(regex, name)]
    # value = []
    # for index in indexs:
        # value.append(flow["value"][:, index])
    # return {"value":np.column_stack(value), "info":[flow["info"][index] for index in indexs]}
# 
# def save(objects, fname):
    # # compute header
    # for object_name in objects:
        # header = ""
        # for info in objects[object_name]["info"]:
            # header += "{info},".format(info=info)
        # header = header[:-1]
        # # save
        # np.savetxt(fname + "__" + object_name + ".csv", objects[object_name]["value"], delimiter=",", header=header)
# 
# def savet(time, objects, fname):
    # # compute header
    # for object_name in objects:
        # header = "time,"
        # for info in objects[object_name]["info"]:
            # header += "{info},".format(info=info)
        # header = header[:-1]
        # # save
        # np.savetxt(fname + "__" + object_name + ".csv", np.column_stack([time] + [objects[object_name]["value"]]), delimiter=",", header=header)
# 
# def saveaf(angular_frequency, objects, fname):
    # # compute header
    # for object_name in objects:
        # header = "angular_frequency,"
        # for info in objects[object_name]["info"]:
            # header += "{info},".format(info=info)
        # header = header[:-1]
        # # save
        # np.savetxt(fname + "__" + object_name + ".csv", np.column_stack([angular_frequency] + [objects[object_name]["value"]]), delimiter=",", header=header)
# 
# def get_property_from_object_name(name, prop):
    # all_properties = name.replace(r"/", "__").split(".")[0].split("__")
    # for prop_name in all_properties:
        # if prop_name.startswith(prop):
            # return float(prop_name[len(prop)+1:].replace("o", ".").replace("_", "."))
    # if prop == "surftimeconst":
        # return 0.0
    # elif prop == "reorientationtime":
        # return 0.0
    # elif prop == "surftimeprefactor":
        # return 0.0
    # elif prop == "dirnoise":
        # return 0.0
    # elif prop == "jnoise":
        # return 0.0
    # elif prop == "swimnoise":
        # return 0.0
    # elif prop == "proportion":
        # return 1.0
    # else:
        # return np.nan

if __name__ == '__main__':
    parse()
