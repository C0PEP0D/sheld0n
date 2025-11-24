#!/usr/bin/env python3

import os
import shutil

def set_flow():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_linear3d')
    os.chdir('../..')
    ## param
    os.system('./.cli_set_parameter param DIM 3')
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{2.0, 2.0, 2.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{false, false, false}"')

def set_solutions():
    os.chdir('param/solutions')
    # passive scalar blobs
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    # reference
    os.system('./.cli_create_new_equation reference')
    os.chdir('reference')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    os.chdir('../..')
    # set parameters
    os.system('./.cli_set_parameter param/solutions/reference IsSplitting false') # removing splitting for the reference
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs IsPostProcessingProfile true') # activate profile post processing
    os.system('./.cli_set_parameter param/solutions/reference IsPostProcessingProfile true') # activate profile post processing

def main():
    set_flow()
    set_solutions()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
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
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation_3d.py", "post_process/generate_scalar_concentration_animation_3d.py")
    shutil.copy(code_dir + "/app/post/generate_profile_c_animation.py", "post_process/generate_profile_c_animation.py")
    shutil.copy(code_dir + "/app/post/plot_profile_c_moments_over_time.py", "post_process/plot_profile_c_moments_over_time.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
