#!/usr/bin/env python3

import os
import glob
import shutil

def set_flow_tgv():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_tgv')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainSize "{8*M_PI, 8*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions_passive_scalar_blobs():
    os.chdir('param/solutions')
    # passive scalar blobs
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    # odor trackers
    os.system('./.cli_create_new_equation odor_trackers_gradient')
    os.chdir('odor_trackers_gradient')
    os.system('./.cli_choose cpp_odor_trackers_gradient')
    os.chdir('..')
    os.chdir('../..')
    # set parameters
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs HasSource true') # add source of scalar
    os.system('./.cli_set_parameter param/solutions/odor_trackers_gradient Number "EnvParameters::cGroupSize/16"') # reduce number of trackers

def main():
    set_flow_tgv()
    set_solutions_passive_scalar_blobs()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "8.0 * M_PI / Dt"')
    os.system('./.cli_set_parameter param/run NSave "NTime/16"')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation_2d.py", "post_process/generate_scalar_concentration_animation_2d.py")
    shutil.copy(code_dir + "/app/post/generate_trajectory_animation_2d.py", "post_process/generate_trajectory_animation_2d.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
