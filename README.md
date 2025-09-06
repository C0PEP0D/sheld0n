# Sheld0n: Lagrangian active particles advection

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)
[![DOI](https://zenodo.org/badge/421041396.svg)](https://zenodo.org/badge/latestdoi/421041396)

A code that enables complex active particle advection in flows. 
The code is still in active development, feel free to ask for features.

This parallel code enables to compute active particle trajectories inside flows. 
It enables the user to specify a complex behaviour of particles. 
It can be used with external flow data, thus enabling to use data from flow simulations or experiments. 
Moreover, provided an internet connection, the software enables to use flows of the [Johns Hopkins Turbulence Database](http://turbulence.pha.jhu.edu/).
This software should be usable on any operating system.
It have been tested on recent Linux distributions (Ubuntu, Archlinux...) and OSX.
On Windows I would advise to use **Windows Subsystem for Linux (WSL)** to avoid any surprises.

This repository contains:

* [Lagrangian active particles advection software](./app) that binds low-level C++ modules into a high-level command line tool.
* A few low-level c++ [modules](./modules) that can be used independently.

## Table of Contents

- [Background](#background)
- [Install](#install)
- [Usage](#usage)
- [Known Issue](#known-issue)
- [Contributing](#contributing)
- [License](#license)

## Background

This software has been produced during my PhD thesis and as part as the European Research Council project: [C0PEP0D](https://c0pep0d.github.io/)

## Install

### Dependencies

The dependencies are standard softwares that may already be installed on your system.
If not, you should be able to install these dependencies with your package manager.

The following must be installed **sytem wide**:

* **git**
* **Python3** and its development libraries
* **Curl** development libraries
* **CMake**
* **ffmpeg**
* A C++17 compliant compiler (**clang++**, **g++**)

The installation has been tested for ArchLinux (2025-08-21) and Ubuntu 24.04.2 LTS (noble).

#### Ubuntu

To install those dependencies on Ubuntu, just execute the following:
```sh
sudo apt update && sudo apt install git python-is-python3 python3-venv python3-dev libcurl4-openssl-dev cmake ffmpeg g++
```

#### OSX

To install those dependencies on MacOS, just execute the following (with **Homebrew** previously installed):
```sh
brew reinstall python3 && brew install tbb git cmake ffmpeg`
```

### Installing

The following command will create a python virtual environment to encapsulate all python dependencies,
then clone the sheld0n project and move into its directory.

```sh
python -m venv venv-sheld0n && cd venv-sheld0n && git clone https://github.com/C0PEP0D/sheld0n.git && cd sheld0n
```

Finally pull submodules and install python dependencies by executing the `install-with-gui.py` script.
When using the code, you can use either a Command Line Interface or a Graphical User Interface (GUI).
When first trying out the code, the usage of the GUI is advised. 
However, if you feel like you do not need it or if the installation with gui does not work, feel free to execute `./install-without-gui` instead.

```sh
./install-with-gui
```
This may take a while, especially during the operation **Building wheel for wxpython (pyproject.toml) ...**

### Updating

In the future, if you'd like to update the code, a simple pull should be enough.
```sh
git pull --recurse-submodules
```

## Usage

### Prerequisites

The solver is written in **C++** and the interface is written in **Python**.
Parameters are set by editing **C++** files or **Cython** parameter files.
**You do not need to know** how to write in **C++**, nor **Cython** prior to the use the code (even though it can help).

Even for a more advance usage of the code, you'll be able to edit the **C++** or **Cython** files
by imitating the examples provided in the code, following the provided tutorial series.

The solver provides a series of tools that can be used either using a command line interface or a graphical user interface.

### General usage

The whole interface of the code is located in the `cases` folder.

You can either use the code using its Graphical User Interface (GUI) or a Command Line Interface (CLI). If you see the file `switch_to_cli` in the `cases` folder, you are currently using the graphical interface. Otherwise you are using the command line interface.

If you start using the code, using the GUI is recommended.
To switch from the `CLI` to the `GUI`, just execute the `switch_to_cli` command.
To switch from the `GUI` to the `CLI`, use the `switch_to_gui` command.

The following covers basic usage of the code, while the documentation is improving, feel free to contact me if you have any questions regarding using this software.

#### GUI Interface

Several files of the code can be executed, for instance by double-clicking on it from your file browser. 
Doing so will open a window that will explain what the program does and how to use it.

> [!NOTE]
> You will have to press the button **run** to run the script and 
> you will have to press the **close** button to exit the program. 

#### CLI Interface

Most scripts provided by this software contain their description, explaining how to use them. One can access this description using the following:

```sh
./script -h
```
or
```sh
./script --help
```

### Quick start

* Go to the `cases` directory.
* Execute the `generate_new_case` script and provide a name for your new case using the **name** argument. 

You can also specify a specific case using the **case** option.
Then navigate in the case and run the case by executing the `run` script.

> [!NOTE]
> If it does not work, it might mean that your default compiler might not support all necessary C++ features.
> Try specifying another C++ compiler, for instance `cpp-14`, `g++-14` or `clang++-18` using the **compiler** option.

* TODO: screenshot

Final data should be in the `post_process` directory. 
Further post processing is provided using python scripts in that directory.

* Move to the `post_process` directory.
* Execute `generate_trajectory_animation.py` (it may take a while).

This should have create a `trajectory_animation.mp4` file that you can open using your video player.

Further post processing can be done using various scripts in that directory.
Run the `--help` option of these scripts to learn how to use them.

Feel free to **edit this scripts** at your convenience and **create your own post processing**.

### Editing simulation parameters

All parameters are included in the `param` directory.
* all files `parameters.h` contain parameters that can be edited.
* `choose` scripts can be used to set `parameters.h` to a chosen default.

For instance, one may use the `param/flow/choose` script to change the flow from a Taylor-Green Vortex to another type of flow. 

If you do so, open the `parameters.h` file in the same directory to see how it has changed.

> [!CAUTION]
> Using a `choice` script will override the `parameters.h` file in the same directory and all changes will be lost.

* optionally the python script `set.py` can be used to set any parameter in the simulation case.

The `set.py`script is intended to be edited by the user. 
The script can search for any occurrences of a parameter and edit it.

> [!CAUTION]
> Using `set.py` edits directly the `parameters.h` files in the parameter tree. 
> If not used correctly, in case of name collision, it can completely corrupt the simulation case.
> If you are not sure of its usage, make sure to copy and save your simulation case before executing the script.

### Advance usage

The simulations can be further customized using the scripts located in `param/solutions`.
A series of tutorials is provided in the [doc](doc) directory to learn how to properly use this code, 
starting with the first tutorial [doc/00-advance-simulation-setup.md](doc/00-advance-simulation-setup.md).

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.
Or just propose features you would like to have implemented in the code.

## License

[MIT](LICENSE) © Centrale Marseille, Rémi Monthiller

