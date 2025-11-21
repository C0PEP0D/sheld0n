#!/usr/bin/env python3

import os
import shutil

def set_flow_tgv():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_tgv')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions_rl_swimmer():
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation rl_swimmer')
    os.chdir('rl_swimmer')
    os.system('./.cli_choose cpp_rl_swimmer')
    os.system('./.cli_remove_equation passive_particles')
    os.chdir('..')
    os.chdir('../..')

def main():
    set_flow_tgv()
    set_solutions_rl_swimmer()
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "8.0 * M_PI / Dt"')
    # remove symbolic link
    os.unlink("run")
    os.unlink("post")
    shutil.rmtree("post_process")

if __name__ == '__main__':
    main()
