#!/usr/bin/env python3

import os
import shutil

def set_flow():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_none')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{false, false}"')

def set_solutions():
    os.chdir('param/solutions')
    # passive scalar blobs
    os.system('./.cli_create_new_equation density_blobs')
    os.chdir('density_blobs')
    os.system('./.cli_choose cpp_density_blobs')
    os.chdir('..')
    # passive particles
    os.system('./.cli_remove_equation passive_particles')
    # back
    os.chdir('../..')

def main():
    set_flow()
    set_solutions()
    # param
    os.system('./.cli_set_parameter param cGroupSize 1')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "16.0 / Dt"')
    os.system('./.cli_set_parameter param/run NSave "NTime/16"')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/generate_scene_animation_2d.py", "post_process/generate_scene_animation_2d.py")
    # remove symbolic link
    os.unlink("learn")
    shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
