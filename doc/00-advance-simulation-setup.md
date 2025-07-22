# Adding new particles to the simulation

Welcome to the tutorial series that will teach you how to use the `sheld0n` code.
This tutorial series assumes you already learnt the basic usage of the code in the [README](../README.md) file.

## Table of Contents

- [Setting up the case](#setting-up-the-case)
- [Global parameters](#global-parameters)
- [Adding new particles](#adding-new-particles)
- [Choosing the particles behavior](#choosing-particles-behavior)
- [Choosing the flow](#choosing-the-flow)
- [Running the simulation](#running-the-simulation)
- [Next tutorial](#next-tutorial)

## Setting up the case

```
Start by creating a new case using the *_generate_new_case script with the name case-00 for instance. 
You do not have to specify anything in the case option for now.
```
```
Then move to the case-00 directory.
```

## Global parameters

All parameters are located in the directory `param`.
Let's first open the file `param/parameters.h` and analyse its content.

In this file, you can:
* set the simulation in 2D or in 3D by setting the variable `DIM`.
* control how the random generation of numbers is managed by setting the variable `randomSeed`
* define optional parameters such as characteristic scales to help setting other parameters of the simulation case.

```cpp
// definition of the dimension of the simulation is in 2D or 3D 
constexpr unsigned int DIM = 2;
// definition of a SpaceVector and a SpaceMatrix,
// this should not be edited
using tSpaceVector = tVector<DIM>;
using tSpaceMatrix = tMatrix<DIM, DIM>;

// main simulation parameters
// the users can add whatever parameters they judge suitable,
// these parameters are accessible from the other parameter files
struct EnvParameters {
	// optional characteristic group size. 
	// should be greater than zero.
	constexpr static const double cGroupSize = 128;
	// optional characteristic scales used to parameterize equations.
	constexpr static const double cLength = M_PI;
	constexpr static const double cTime = M_PI;
	constexpr static const double cVelocity = cLength / cTime;
	// characteristic domain (mainly used to define bounds for random initialization)
	inline static const tSpaceVector cDomainCenter = tSpaceVector::Zero();
	inline static const tSpaceVector cDomainSize = {2 * M_PI, 2 * M_PI};
	inline static const std::array<bool, DIM> cDomainIsAxisPeriodic = {true, true};
	// seed used for random generation
	constexpr static const unsigned int randomSeed = 0;
};
```

Note that the `cGroupSize` parameters will control the number of particles in the simulation.
Let's move on for now, we'll come back to these parameters later.

## Adding a new particles

The default simulation case created using the `*_generate_new_case` script is a 2D simulation of passive particles in a Taylor-Green flow.
Let's first try to add some buoyant particles in the flow.

```
Move to the param/solutions directory.
```

This directory contains the parameters that describe the equation of motion of all particles in the flow that will be solved by the flow.

```
Check the content of the directory.
```

The `parameters.h` file lists the equations to be solved in your simulation.
Contrary to most of the other `parameters.h` files in the `param/` directory, 
this particular file is solely meant to be modified using the scripts 
`*_batch_copy_equation`, `*_copy_equation`, `*_create_new_equation`, `*_remove_equation`, `*_rename_equation`.

Each execution of a script will change the directories content while editing the `parameters.h` file.

For now, our simulation only solves the trajectory of passive particles, represented by the `passive_particles` directory.
Let's try to add **buoyant particles** in the flow using the `*_create_new_equation` script.

```
Execute the *_create_new_equation script and set the name of the new equation to buoyant_particles using the **name** argument. 
Select the pyx_passive_particles as the parameters option.
```

> [!NOTE]
> If you are using the GUI interface, press the **run** button 
> when you are done configuring.
> Once it is done, you can press the **exit** button to close the window.
>
> The **pyx_** prefix specifies that the equation is describe the Cython interface, recommended for beginners. 
> The **cpp_** prefixed equations use the more advance and flexible C++ interface.

```
Check again the content of the directory.
```

You will notice that a directory `buoyant_particles` has appeared.
However because we have selected the **pyx_passive_particles** option, despite its name, the equation that will be solve is that of passive particles.

```
Move into the buoyant_particles directory and check its content.
```

Let's open the `parameters_buoyant_particles.pyx` file and analyse it.
It is a **Cython** file decomposed in various functions:

1. **constrain**: used to constrain state variables if necessary (for instance normalize a unit vector).
2. **prepare**: used to prepare the solver before the computation, is mainly used to prepare the flow to query the data that will be used in other functions (particularly important when you rely on the Johns Hopkins Database).
3. **state_temporal_derivative**: used to describe the equation to be solved by describing the temporal derivative of the state variable to be solved.
4. **init**: used to initialize the state variable at the start of the simulation
5. **post**: post process the state variable and stores data in a dictionary

If you are not familiar with **Cython**,
**Cython** is a tool that can be used to generate **C++** files using a **Python**-like syntax.
If you are interested in **Cython**, feel free to check their website.

> [!CAUTION]
> In this solver, **Cython** files have to compile into a pure **C++** depraved of any **Python** calls.
> This means that you are not allowed 1) to import any Python modules, 2) use directly any Python object (such as numpy arrays, python strings, python lists or python dictionaries).
> You will have to use the alternative modules and objects provided by the solvers and you will have to declare all the variables you use using **cdef**.

Here, the most important difference with **Python** is that you will have to declare the variables with their type before using them.
As an example, rather than declaring `a = 1`, you will declare `cdef int a = 1`. Similarly `a = 1.0` will be `cdef double a = 1.0`. 
And if you want to declare a vector $\vec{a} = (1.0, 0)$ you will state `cdef c0p.tSpaceVector a = c0p.tSpaceVector(1.0, 0.0)`.

> [!NOTE]
> Here the word **SpaceVector** refers to a vector of the dimension of the current dimension of the simulation (2 for 2D simulation, 3 for 3D simulation). Similarly a **SpaceMatrix** is 2x2 matrix in 2D and 3x3 matrix in 3D.
>
> You may further note the use of View or ViewConst vectors in function arguments.
> This distinction is used to avoid the copy of data and therefore avoid performance loss. 
> Do not bother too much about that, just consider these as normal maths vectors, you should not have to edit these parameters.

Let's now focus on the **state_temporal_derivative** function.

Here `x` represents the particle as a *SpaceVector* (vector of dimension 2 in 2D).
`t` is a floating number (*double*) giving the current time.
Finally `dx` describes the temporal derivative of the particle position, i.e. its velocity.

The aim of this function is set `dx` as a function of `x` and `t` to describe the behavior of our particle.

As stated above, the behavior of our new equation added in the solver is that of a passive particle in a flow.
The motion of such a particle is described by the following equation
```math
\frac{d \vec{x}}{dt} = \vec{u} \left ( \vec{x}, t \right ) \, \mathrm{,}
```
with $\vec{x}$ the position of the particle, $\vec{u}$ the flow velocity field and $t$ the time.
This is exactly what the last line of this function states.

## Choosing the particles behavior

Now that we analysed the `parameters_buoyant_particles.pyx` file of a passive particle, we want to change that file to match the behavior of a **buoyant** particle.
We could manually edit the `parameters_buoyant_particles.pyx`, but we can also use the `*_choose` script in the same directory to choose another default behavior.

```
Close the parameters_buoyant_particles.pyx file and run the *_choose script with pyx_buoyant_particles as the **choice** option.
```

> [!CAUTION]
> Using a `*_choose` script will override the `parameters.h` and the `parameters_buoyant_particles.pyx` files and all changes will be lost.

If you open again the `parameters_buoyant_particles.pyx` file, you can see it has changed.
You may note two new parameters defined at the top of the file (`buoyant_velocity` and `buoyancy_direction`) and a different definition of the temporal derivative corresponding to the following equation
```math
\frac{d \vec{x}}{dt} = \vec{u} \left ( \vec{x}, t \right ) + V_{\mathrm{buoyancy}} \vec{z} \, \mathrm{,}
```
with $V_{\mathrm{buoyancy}}$ the buoyancy induced velocity of the particle and $\vec{z}$ the vertical.
Now our buoyant particles are setup. 

Now that we know how to do, let's just add inertial particles to the simulation just for fun.

```
Move back to the param/solutions directory
```
```
Execute the *_create_new_equation script with the name inertial_particles and with the options pyx_inertial_particles. 
This avoids having to use the choose script to change the particle behavior.
```

Before moving on, let's just analyse the `parameters_inertial_particles.pyx` file of our inertial particles.
First of all, the motion of inertial particles is described by the following equations
```math
\frac{d \vec{x}}{dt} = \vec{v}
```
```math
\frac{d \vec{v}}{dt} = \frac{ u \left ( \vec{x}, t \right ) - \vec{v} }{\tau} \, \mathrm{,}
```
with a $\vec{v}$ the velocity of the particle and $\tau$ a constant reaction time.

This time, this particle is described by two state variables, its position (`x`) and its velocity (`v`).

You can read further the file to understand how having two state variable changes:
* the way to define the temporal derivative.
* how to initialize the state of your particles.
* how to add several state variables in the post processing.

Before moving on, let's open the file **parameters.h** of the inertial particles.
At the beginning of the file, you will notice the `StateSize` and the `Number` parameters.
The `StateSize` parameter defines the dimension of the state variable that describes the whole state of our particle.
In this particular case, the state variable of the particle is both composed of its position `x` and its velocity `v`.
Therefore the total size is `2 * DIM` with `DIM` the dimension of simulation (2 for 2D and 3 for 3D).
When you use the Cython interface, you will not have to change this parameter (unless you know what you are doing).

```cpp
// ---------------- CUSTOM EQUATION PARAMETERS START

static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
// feel free to add parameters if you need
static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group

// ---------------- CUSTOM EQUATION PARAMETERS END
```

However the `Number` parameter is important as it controls how any instances of the particle will be added to the simulation.
Currently it is set to `EnvParameters::cGroupSize`. 
This parameter has been set to `16` in the `param/parameters.h` file.
To change that number you can either edit directly the parameter `EnvParameters::cGroupSize` but it might most likely change the number of particles for all particles in the simulation.Or one can directly change the number in this file.

Here are two ways to set the number of particles to `32`:
```cpp
static const unsigned Number = 2 * EnvParameters::cGroupSize;
static const unsigned Number = 32;
```

> [!CAUTION]
> When you edit **.h** files, these are **C++** files.
> Therefore the syntax is slightly different.
> Be sure to edit only the right hand side (after the "=") and to keep the ";" at the end of the line.

## Choosing the flow

Similarly the flow can be chosen and its parameters edited in the `param/flow` directory

> [!CAUTION]
> If you need a 3D flow, you will also have to change the `DIM` parameter in the `param/parameters.h` file.
> You also may also have to change particle parameters where you define explicitly 2D vectors and change them to 3D vectors.

## Running the simulation

To control further the simulation, three other directories exists with parameters you can set.
* The `param/run` directory where you can set the parameters of the solver (such as the time step, the total time of the simulation, etc...).
* The `param/post` directory where you can control the post processing.

Once that is done, we can run the simulation. 

```
Execute the `*_run` script at the root directory of the current case.
```

> [!NOTE]
> You may note that compilation takes a long time compared to the time of the simulation.
> This choice of compiling again each time you change parameters has been made to increase
> convenience and performance. In real use cases with a lot of particles, the compilation
> time becomes negligible compared to the simulation time. 
>
> To speed things up, you can use the `-j` option to run the compilation in parallel.

Finally one can visualize its simulation by generating an animation of the particle trajectories.

```
Move to post_process directory and execute the generate_trajectory_animation.py script (it may take a while). 
It should have created the trajectory_animation.mp4 file.
```

## Cleaning the simulation

The `time` directory at the root of the case contains the saved state of all particles for each time step saved once the simulation has been run.
If the simulation stops before it ends for any kind of reason, when running again the simulation, the last saved simulation step in `time` will be used to continue the simulation.
This also means that you can increase the total number of time steps after a simulation without having to run again the beginning of the simulation.
However, you'll need to remove the directory `time` to rerun the simulation from the beginning.
To do so, one can use the `clean_time` script.

Similarly, the directory `post_process/time` is created when running the post processing and can be continued if the post processing ended prematurely.

In certain cases, if the simulation or the post_processing was stopped while writing a file, the last time step may be corrupted.
In that case, just delete the last step (the last directory in `time` directory) to continue from the previous step.

Because the `*_run` and the `*_post` are separated,
you may change any post-processing function after the simulation has been executed without having to run again the whole simulation.
However, in that case, make sure you delete the directory `post_process/time` before running again the `post` script.
To do so, one can use the `post_process/clean` script.

Finally if you change the name of your case (or copy and paste your case into a new name), the code will have to reconfigure the compilation.
To do that, just delete the directory `build` in your case.
To do so, one can use the `clean_build` script.

## Next tutorial

That's the end of this first tutorial. 
In the next tutorial [01-custom-pyx-equations.md](01-custom-pyx-equations.md), 
you'll learn how to customize particles and flows to encode your own equations into the code using a python interface.
