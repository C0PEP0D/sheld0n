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
    parser = argparse.ArgumentParser(description='Chain post processing')
    return parser.parse_args()

def main():
    # get positions
    time = libpost.get_time();
    objects_pos = libpost.get_objects_properties(["s_.*__pos_0", "s_.*__pos_1", "s_.*__pos_2"])
    # sort stuff based on s
    result = {}
    for object_name in objects_pos:
        for i in range(len(objects_pos[object_name]["info"])):
            s = libpost.get_property_from_object_name(objects_pos[object_name]["info"][i], "s")
            if s in result:
                result[s].append({"info":objects_pos[object_name]["info"][i], "value":objects_pos[object_name]["value"][:, i]})
            else:
                result[s] = [{"info":objects_pos[object_name]["info"][i], "value":objects_pos[object_name]["value"][:, i]}]
    # extract snapshot
    for snapshot_id in range(len(time)):
        snapshot = []
        for s, data in result.items():
            snapshot.append([s] +  [d["value"][snapshot_id] for d in data])
        # save snapshot
        np.savetxt("snapshot__t_{time}.csv".format(time=str(time[snapshot_id]).replace(".", "o")), np.stack(snapshot), delimiter=",", header="s,pos_0,pos_1,pos_2")

if __name__ == '__main__':
    args = parse()
    main()
