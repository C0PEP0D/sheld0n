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

The following must be installed:
* **Python** (`sudo apt install python`) with additional modules
	* **numpy**, `python -m pip install numpy`
	* **matplotlib**, `python -m pip install matplotlib`, used for plotting
* **CMake**, `sudo apt install cmake`
* **Threading Building Block Library**, `sudo apt install tbb`
* a c++20 compliant compiler such as one of the following:
	* **gcc** `v14`, `sudo apt install gcc-14`
	* **clang** `v18`, `sudo apt install clang-18`
* **ffmpeg**, `sudo apt install ffmpeg`, used to generate animations

### Installing

Start by cloning this repository on some of its submodules.

```sh
$ git clone --recursive --no-checkout thirdparty/rl-tools
```
Make sure to add the `--no-checkout thirdparty/rl-tools` option even if you'd like to use reinforcement learning tools.
If you'd like to have this tools, just execute the following afterwards.

```sh
$ git submodule update --init thirdparty/rl-tools
```

And that's it!

### Updating

A simple pull should be enough.

```sh
$ git pull --recurse-submodules
```

## Usage

### Prerequisites

The solver is written in **C++** and the command line interface is written in **Python**.
**You do not need to know** how to write in C++ nor in Python prior to the use the code (even though it can help).

Even for a more advance usage of the code, you'll be able to edit the **C++** and **Python** files 
by imitating the examples provided in the code, in particular if you follow the provided tutorial series.

However as the solver is provided as a series a command line tools, you will need to be familiar with the use of
a terminal emulator.

### General usage

The following covers basic usage of the code, while the documentation is improving, feel free to contact me if you have any questions regarding using this software.

Most scripts provided by this software contain their description, explaining how to use them. 
One can access this description using the following:

```sh
$ ./script -h
```
or
```sh
$ ./script --help
```

### Quick start

Go to the cases folder and and execute the script `generate_new_case` providing a name for that case:

```sh
$ cd cases
$ ./generate_new_case my_new_case
```

Then navigate in the case and run the case.

```sh
$ cd my_new_case
$ ./run
```

> [!NOTE]
> If it does not work, it might mean that your default compiler might not support all necessary C++ features.
> Try specifying another C++ compiler, `./run -c g++-14` or `./run -c clang++-18`.

Once the simulation has finished, one can run some post processing:

```sh
$ ./post
```

> [!NOTE]
> Similarly, one can specify another C++ compiler if necessary, `./post -c g++-14` or `./post -c clang++-18`.

Final data should be in the `post_process` directory. 
Further post processing is provided using python scripts in that directory.
For instance, you can visualize your simulation using:

```sh
$ ./generate_trajectory_animation.py
```

Further post processing can be done using various scripts in that directory.
Run the `--help` option of these scripts to learn how to use them.

Feel free to edit this scripts at your convenience and create your own post processing.

### Editing simulation parameters

All parameters are included in the `param` directory.
* all files `parameters.h` contain parameters that can be edited.
* `choose` scripts can be used to set `parameters.h` to a chosen default.

For instance use the `param/flow/choose` script to change the flow from a Taylor-Green Vortex to a uniform flow. 
```sh
$ cd param/flow
$ ./choose uniform
```
Then open the `parameters.h` file in the same directory to see how it has changed.
Use the `-h` or `--help` option to see all available choices.

> [!CAUTION]
> Using a `choice` script will override the `parameters.h` file in the same directory and all changes will be lost.

* optionally the python script `set.py` can be used to set any parameter in the simulation case.

The `set.py`script is intended to be edited by the user. 
The script can search for any occurrences of a parameter edit it.

> [!CAUTION]
> Using `set.py` edits directly the `parameters.h` files in the parameter tree. 
> If not used correctly, in case of name collision, it can completely corrupt the simulation case.
> If you are not sure of its usage, make sure to copy and save your simulation case before executing the script.

### Advance usage

The simulations can be further customized using the scripts located in `param/solutions`.
A series of tutorials is provided in the [doc](doc) directory to learn how to properly use this code, 
starting with the first tutorial [doc/00-advance-simulation-setup.md](doc/00-advance-simulation-setup.md).

## Known issue

There is a memory leak when using the **JHTDB** flow.
If you do use this flow in your simulations, just kill the process when too much memory is used and rerun it.

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.
Or just propose features you would like to have implemented in the code.

## License

[MIT](LICENSE) © Centrale Marseille, Rémi Monthiller

