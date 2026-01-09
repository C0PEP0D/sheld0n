#!/usr/bin/env python3

import os
import glob
import shutil

def set_flow():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_random_sine3d')
    os.chdir('../..')
    os.system('./.cli_set_parameter param DIM 3')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainCenter "{M_PI, M_PI, M_PI}"')
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{false, false, false}"')

def set_solutions():
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    os.chdir('../..')
    # set parameters
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs HasInit true') # activate of init
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitX "{M_PI, M_PI, M_PI}"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitS "tSpaceVector({1.0, 1.0e-2, 1.0}).asDiagonal()"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Diffusivity "1e-6"')
    # set post processing
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs IsPostProcessingConcentrationProfile true') # activate profile post processing
    
def main():
    set_flow()
    set_solutions()
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
    shutil.copy(code_dir + "/app/post/plot_cmax_over_time.py", "post_process/plot_cmax_over_time.py")
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation_3d.py", "post_process/generate_scalar_concentration_animation_3d.py")
    shutil.copy(code_dir + "/app/post/generate_profile_c_animation.py", "post_process/generate_profile_c_animation.py")
    shutil.copy(code_dir + "/app/post/plot_profile_c_moments_over_time.py", "post_process/plot_profile_c_moments_over_time.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
