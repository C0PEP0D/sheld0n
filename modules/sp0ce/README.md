# sp0ce : Simple library of geometry utilities

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

A simple C++ library that helps with various geometrical computations.
Also includes a bin space partition method for fast proximity detection.

Simple examples are provided and should be enough to explain how to use this library.

This repository contains:

1. The software itself provided as a header only library in the directory [include/sp0ce](./include/sp0ce)
2. A few [examples](./examples).

## Table of Contents

- [Background](#background)
- [Install](#install)
- [License](#license)

## Background

This library is developed as part of [PL0F](https://github.com/rmonthil/pl0f), a Lagrangian solver intended for simple fluid flow simulations.

## Install

### Dependencies

The dependencies are standard softwares that may already be installed on your system.
If not, you should be able to install these dependencies with your package manager.

* [**CMake** `v?`](https://cmake.org/download/)
* a c++20 compliant compiler, such as [**gcc** `v10`](https://gcc.gnu.org/) or higher must be installed. For Ubuntu users: [ppa](https://launchpad.net/%7Ejonathonf/+archive/ubuntu/gcc?field.series_filter=bionic).
* the [**Threading Building Block Library** `v2018`](https://github.com/ibaned/tbb) or higher must be installed ([this version](https://github.com/wjakob/tbb) that enables is installing it using CMake is advised)

Examples:
* [**Eigen**](https://eigen.tuxfamily.org) must be installed
* [**s0s**](https://github.com/C0PEP0D/s0s) must be installed

Chain example:
* [**m0sh**](https://github.com/C0PEP0D/m0sh) must be installed
* [**p0l**](https://github.com/C0PEP0D/p0l) must be installed

The examples assume the following directory tree structure:
```bash
..
 ├── .
 │   │── sl0
 │   │── s0s
 │   │── (m0sh)
 │   └── (p0l)
 └── thirdparty
     └── eigen
```
One should either install these dependencies accordingly, or adapt their path in the **CMakeList.txt** file of the examples.

### Installing

Start by cloning this repository.

```sh
$ git clone https://github.com/C0PEP0D/sl0.git
```

### Examples

Running an example:

```bash
$ cd examples/point
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./point
```

### Updating

A simple pull should be enough.

```sh
$ git pull
```

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.

## License

[MIT © Rémi MONTHILLER.](./LICENSE)
