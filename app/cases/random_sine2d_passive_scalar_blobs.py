#!/usr/bin/env python3

import os
import glob
import shutil
import numpy as np

def set_flow():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_random_sine2d')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainCenter "{M_PI, M_PI}"')
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions():
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    os.chdir('../..')
    # set parameters
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Diffusivity "1e-3"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs HasInit true') # activate of init
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitX "{M_PI, M_PI}"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitS "tSpaceVector({5e-1, 5e-3}).asDiagonal()"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs SplitSizeFactor "1e-1"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Cth "1e-5"')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs IsPostProcessingParticles false')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs IsPostProcessingConcentrationOnGrid true')
    # batch SplitSizeFactor
    os.chdir('param/solutions')
    os.system('./.cli_batch_copy_equation passive_scalar_blobs -p SplitSizeFactor -v ' + " ".join([str(v) for v in np.logspace(-2, -1, 4)]))
    os.system('./.cli_remove_equation passive_scalar_blobs')
    # batch OverlapFactor
    passive_scalar_blobs = " ".join(glob.glob("passive_scalar_blobs__*"))
    os.system('./.cli_batch_copy_equation ' + passive_scalar_blobs + ' -p SplitDistanceFactor -v ' + ' '.join([str(v) for v in np.linspace(0.2, 1.0, 9)]))
    os.system('./.cli_remove_equation ' + passive_scalar_blobs)
    os.chdir('../..')

def main():
    set_flow()
    set_solutions()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
    # run
    os.system('./.cli_set_parameter param/run Dt "0.001"')
    os.system('./.cli_set_parameter param/run NTime "int(10.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime/100"')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_cmax_over_time.py", "post_process/plot_cmax_over_time.py")
    shutil.copy(code_dir + "/app/post/generate_scene_animation_2d.py", "post_process/generate_scene_animation_2d.py")
    shutil.copy(code_dir + "/app/post/comparative_validation_against_dns.py", "post_process/comparative_validation_against_dns.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
