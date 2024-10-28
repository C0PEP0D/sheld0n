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

def get_post(time_dir, post_name):
    post_filename = time_dir + "/" + post_name + ".csv"
    return {"info":get_file_header(post_filename), "value":np.loadtxt(post_filename, delimiter=",")}

# def get_flow(time_dir):
    # return get_object(time_dir, "flow")
# 
# def get_mesh():
    # object_filename = "mesh.csv"
    # return {"info":np.array(get_file_header(object_filename)), "value":np.loadtxt(object_filename, delimiter=",")}

def get_post_properties(obj, properties):
    regex = ""
    for prop in properties:
        regex += "{prop}$|".format(prop=prop)
    regex = regex[:-1]
    # extract indexs
    indexs = [index for index, name in enumerate(obj["info"]) if re.search(regex, name)]
    # return
    return {"info":[obj["info"][i] for i in indexs], "value":obj["value"][indexs]}

def get_post_names():
    post_names = []
    time_dirs = glob.glob("time/*")
    if time_dirs:
        post_paths= glob.glob(time_dirs[0] + "/*")
        for path in post_paths:
            post_names.append(path.split("/")[-1].split(".")[0])
    else:
        raise NameError('No data found')
    return post_names

def get_properties_from_string(name):
    # init
    properties = {}
    # extract properties
    name_properties = name.replace(r"/", "__").split(".")[0].split("__")
    for prop in name_properties:
        prop_split = prop.split("_")
        if len(prop_split) > 1:
            try:
                properties["_".join(prop_split[:-1])] = float(prop_split[-1].replace("o", ".").replace("m", "-"))
            except:
                pass
    # return
    return properties

if __name__ == '__main__':
    parse()
