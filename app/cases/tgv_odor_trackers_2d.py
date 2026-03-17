#!/usr/bin/env python3

import os
import shutil

def set_flow():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_tgv')
    os.chdir('../..')
    # flow
    os.system('./.cli_set_parameter param/flow Velocity 0.25')
    # params
    os.system('./.cli_set_parameter param cLength "M_PI"')
    os.system('./.cli_set_parameter param cTime "M_PI"')
    os.system('./.cli_set_parameter param cDomainSize "{4.0 * M_PI, 4.0 * M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions():
    os.chdir('param/solutions')
    # passive scalar blobs
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    # odor emitters
    os.system('./.cli_create_new_equation odor_emitters')
    os.chdir('odor_emitters')
    os.system('./.cli_choose cpp_odor_emitters')
    os.chdir('..')
    # odor trackers
    os.system('./.cli_create_new_equation odor_trackers_gradient')
    os.chdir('odor_trackers_gradient')
    os.system('./.cli_choose cpp_odor_trackers_gradient')
    os.chdir('..')
    # back
    os.chdir('../..')
    # set parameters
    ## passive scalar blobs
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Diffusivity "2e-3"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitS "tSpaceVector({1.0e-1, 1.0e-1}).asDiagonal()"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs SplitSizeFactor "1e-1"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Cth "1e-2"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs IsPostProcessingConcentrationOnGrid true')
    ## odor emitters
    os.system('./.cli_set_parameter param/solutions/odor_emitters SourceS "tSpaceVector({5.0e-3, 5.0e-3}).asDiagonal()"')
    os.system('./.cli_set_parameter param/solutions/odor_emitters SourceReactionTime "1.0/32.0"')
    ## odor trackers
    os.system('./.cli_set_parameter param/solutions/odor_trackers_gradient Number "EnvParameters::cGroupSize/16"') # reduce number of trackers
    # reduce number of trackers

def main():
    set_flow()
    set_solutions()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "128.0/Dt"')
    os.system('./.cli_set_parameter param/run NSave "NTime/16"')
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
