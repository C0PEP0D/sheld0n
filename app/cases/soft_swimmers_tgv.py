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
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions_soft_swimmers():
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation soft_swimmers')
    os.chdir('soft_swimmers')
    os.system('./.cli_choose pyx_soft_swimmers')
    os.chdir('..')
    # time horizon
    os.system('./.cli_batch_copy_equation soft_swimmers -p stiffness -v ' + " ".join([str(v) for v in [0.125, 0.25, 0.5, 1.0, 2.0, 4.0, 8.0]]))
    os.system('./.cli_remove_equation soft_swimmers')
    # swimming velocity
    soft_swimmers = " ".join(glob.glob("soft_swimmers__*"))
    os.system('./.cli_batch_copy_equation ' + soft_swimmers + ' -p mass -v ' + ' '.join([str(v) for v in [1.0, 4.0, 16.0, 64.0]]))
    os.system('./.cli_remove_equation ' + soft_swimmers)
    os.chdir('../..')

def main():
    set_flow_tgv()
    set_solutions_soft_swimmers()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "8.0 * M_PI / Dt"')
    os.system('./.cli_set_parameter param/run NSave 16')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_vertical_migration_performance_over_stiffness.py", "post_process/plot_vertical_migration_performance_over_stiffness.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
