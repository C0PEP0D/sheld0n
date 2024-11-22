# Writing your own equations

Here you'll learn how to customize particles and flows to encode your own equations into the code.

## Table of Contents

- [Writing in C++](#writting-in-c++)
- [Custom particle equation](#custom-particle-equation)
- [Custom post processing](#custom-post-processing)
- [Custom flow equation](#custom-flow-equation)
- [Next tutorial](#next-tutorial)

## Writing in C++

Right now, you'll have to write your own equations in **C++** however 
you will not have to bee an expert in **C++** to specify your own equations.
We will get through this together by analysing and replicating the examples provided.

When starting modifying the **C++** files, the risk is to generate compilation errors.
**C++** compilers tend to generate long and sometime overwhelming errors.
They have their own language which require some time to get into but 
once you get familiar with it, you find the compilation errors very descriptive.

So if you get a compilation error, make sure to read the output carefully and you should be able to solve it. 
If not feel free to **open an issue** or contact me if you need any help.

## Custom particle equation

First let's generate a new case to avoid breaking the first tutorial case.
Rather than generating a new case from scratch, let's just copy our first case.
```sh
$ cd cases
$ ls
case_00  generate_new_case
$ cp -r case_00 case_01
$ ls
case_00 case_01 generate_new_case
```

Let's move into it, clean entirely the simulation and create a new equation.
```sh
$ cd case_01
$ ./clean
$ cd param/solutions
$ ./create_new_equation custom_particles
$ cd custom_particles
```

As an exercise, let's try to create a particle that is both buoyant and inertial.
The motion of such a particle would be described by the following equations
```math
\frac{d \vec{x}}{dt} = \vec{v}
```
```math
\frac{d \vec{v}}{dt} = \frac{ u \left ( \vec{x}, t \right ) + V_{\mathrm{buoyancy}} \vec{z} - \vec{v} }{\tau} \, \mathrm{.}
```

While this equation is not included in the choices available in the solver, `buoyant_particles` and `inertial_particles`
are both already available.
By merging together both behavior, we should be fine.

Let's first get the `parameters.h` for buoyant particles and save it to have access to it later.
```sh
$ ./choose buoyant_particles
$ cp parameters.h save_buoyant_parameters.h
```

Let's now start our new custom behavior from inertial particles.
```sh
$ ./choose inertial_particles
```

We can now open both file at the same time and try to merge the `save_buoyant_parameters.h` file into the `parameters.h` file.
Let us first copy paste the buoyancy parameters into our parameters.
```cpp
22	// ---------------- CUSTOM EQUATION PARAMETERS START
23	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
24	// feel free to add parameters if you need
25	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
26	static constexpr double ReactionTime = 1.0;
27	static constexpr float BuoyantVelocity = 0.5; // <--- ADDED
28	static constexpr std::array<double, DIM> BuoyancyDirection = {0.0, 1.0}; // <--- ADDED
29	// ---------------- CUSTOM EQUATION PARAMETERS END
```

Then we need to modify the definition of the temporal derivative of our state variables to match the previous equation.
To do so, let's first copy the line **38** of `save_buoyant_parameters.h` into our `parameters.h` file.
This line gives us access to the vertical in vector form.
```cpp
37			// ---------------- CUSTOM EQUATION START
38			// parameters <--- ADDED
39			const tView<const tSpaceVector> z(BuoyancyDirection.data()); // <--- ADDED
40			// input
41			const tView<const tSpaceVector> x(pState);
42			const tView<const tSpaceVector> v(pState + DIM);
43			// flow
44			const tSpaceVector u = Flow::getVelocity(x.data(), t);
45			// output
46			tView<tSpaceVector> dX(dState.data());
47			tView<tSpaceVector> dV(dState.data() + DIM);
48			dX = v;
49			dV = (u - v) / ReactionTime;
50			// ---------------- CUSTOM EQUATION END
```

Finally, we just have to change the line **49** to match our new equation.
```cpp
49			dV = (u + BuoyantVelocity * z - v) / ReactionTime;
```

Congrats ! You implemented your first custom equation into the solver.
The code should already be able to run and solve your equation,
but before moving on, let's try to edit both the `init` and the `post` function too.

Starting with the `init`, it might make more sense to initialize the velocity of particles to
their buoyant velocity.
```cpp
66		// ---------------- CUSTOM INIT START
67		// interpret BoxCenter and BoxSize as vectors
68		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
69		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
70		// loop over each member of the variable group
71		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
72			// get the state variable of the subIndex member of the group
73			double* pSubState = tVariable::state(pState, subIndex);
74			// parameters <--- ADDED
75			const tView<const tSpaceVector> z(BuoyancyDirection.data()); // <-- ADDED
76			// interpret subState as a tSpaceVector
77			tView<tSpaceVector> x(pSubState);
78			tView<tSpaceVector> v(pSubState + DIM);
79			// set the initial position of this member
80			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
81			v = z * BuoyantVelocity; // <--- EDITED
82		}
83		// ---------------- CUSTOM INIT END
```

Finally, in this context, it might be of interest to extract the flow velocity sampled
by the particles along their trajectories.
```cpp
91		// ---------------- CUSTOM INIT START
92		tSpaceVector xAverage = tSpaceVector::Zero();
93		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
94			const double* pSubState = tVariable::cState(pState, subIndex);
95			const tView<const tSpaceVector> x(pSubState);
96			const tView<const tSpaceVector> v(pSubState + DIM);
97			const tSpaceVector u = Flow::getVelocity(x.data(), t); // <--- ADDED
98			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_0"] = x[0];
99			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_1"] = x[1];
100			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__vel_0"] = v[0];
101			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__vel_1"] = v[1];
102			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__u_0"] = u[0]; // <--- ADDED
103			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__u_1"] = u[1]; // <--- ADDED
104			xAverage += x;
105		}
106		xAverage /= Number;
107		output["custom_particles__average_pos_0"] = xAverage[0];
108		output["custom_particles__average_pos_1"] = xAverage[1];
109		// ---------------- CUSTOM INIT END
```

Once everything is setup, we can run the simulation and the post processing.
```sh
$ cd ../../..
$ ./run
[...]
$ ./post
$ cd post_process
```

## Custom post processing

We could directly use the Python scripts available to plot trajectories or vertical displacement over time of all our particles.
These scripts focus on the position of particles extracted from the simulation.
However, we also extract the velocity of these particles and the flow velocity sampled by these particles.

Let's try to build another post processing script that exploits this data.
First, we can copy the `plot_over_time.py` script to avoid starting from scratch. 
```sh
$ cp plot_over_time.py plot_custom.py
```

Then let's open that script to start analyzing it.
If you are familiar with Python, you should recognize some of the imported modules with one exception.
```python
import libpost
```
The module `libpost` is a module internal to this software that helps reading the data extracted from simulations.

Next we can see two function within the script:
* the function `parse` used to define the command line arguments of the script.
* the function `main` responsible for most of the script

We'll ignore the function `parse` for now to focus on the function `main`.
Let's analyse this function from top to bottom.

```python
20 def main(input_equation_list, input_color_list):
21	# equations
22	if input_equation_list:
23		equation_name_list = input_equation_list
24	else:
25		print("INFO: Reading equation names...", flush=True)
26		equation_name_list = libpost.get_equation_names()
27	# colors
28	if input_color_list:
29		color_list = input_color_list
30	else:
31		cmap = plt.cm.get_cmap("plasma", len(equation_name_list))
32		color_list = [cmap(index) for index in range(len(equation_name_list))]
```
This first part is responsible of adapting the code if the option of the script are not provides.
It defines searches for the names of the equation to be post processed and defines default colors for the plot.
We will not this part of the code here so let's move on.

```python
33	print("INFO: Reading time...", flush=True)
34	time_dir_array, time_array = libpost.get_time()
```
This part reads the time of all time steps that have been post processed and stares it in two arrays:
* `time_dit_array` an array of strings containing all paths in the directory `post_process/time`.
* `time_array` an array of floating numbers corresponding to these times.
This will be useful in most cases when post processing the data so we will leave it unchanged.

This next part is important.
```python
35	print("INFO: Reading equation property over time...", flush=True)
36	pos_1_over_time = {}
37	for equation_name in equation_name_list:
38		pos_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array))
```
It uses the function `libpost.get_equation_property_over_time` to read the property `"pos_1"` of the equation `equation_time` in the directory paths provided by `time_dir_array`.
In other words, it returns the vertical component of the position of all particles of type `equation_name` over time.
We will change this part later on to read the wanted properties from our particles.

The rest of the file plots this data in different ways.
We won't get into details here. 
Everything should be self explanatory in particular if you know Python.

Let's just keep the last plot to have an example for now and delete the two others that won't be necessary.
Your main function should then look like the following.
```python
18 def main(input_equation_list, input_color_list):
	# [...]
33	print("INFO: Reading equation property over time...", flush=True)
34	pos_1_over_time = {}
35	for equation_name in equation_name_list:
36		pos_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array))
37	print("INFO: Plotting property difference to initial time average ...", flush=True)
38	for equation_index, equation_name in enumerate(equation_name_list):
39		plt.plot(time_array, (pos_1_over_time[equation_name] - pos_1_over_time[equation_name][0]).mean(1), color=color_list[equation_index], label=equation_name)
40	plt.xlabel('$t$')
41	plt.ylabel(r'$\langle y \rangle$')
42	plt.legend()
43	plt.show()
```

We are now interested by the flow velocity sampled by our particles.
Therefore let's change the first part to read the flow velocity sampled by particles rather than its vertical position.
```python
33	print("INFO: Reading equation property over time...", flush=True)
34	u_0_over_time = {}
35	u_1_over_time = {}
36	for equation_name in equation_name_list:
37		u_0_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__u_0", time_dir_array))
38		u_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__u_1", time_dir_array))
```

Now for the plot, plotting the sampled flow velocity over time would have little interest.
We can rather use the `plt.hist` function to plot the probability function of the sampled flow velocity.
To do that change the next part to the following.
```python
39	print("INFO: Plotting property difference to initial time average ...", flush=True)
40	for equation_index, equation_name in enumerate(equation_name_list):
41		plt.hist(u_1_over_time[equation_name].flatten(), bins=32, density=True, histtype="stepfilled", color=color_list[equation_index], label=equation_name)
42	plt.xlabel(r'$u_y$')
43	plt.ylabel('pdf')
44	plt.legend()
45	plt.show()
```

Finally, you should be able to execute it using the following command:
```sh
$ ./plot_custom.py -e custom_particles
```

> [!NOTE]
> The `-e` option helps to specify which particles you want the post plot to be applied to.
> By default not specifying this option means post processing all equations. 
> However if you do so, only the histogram for the `custom_particles` will be plotted as
> the flow velocity sampled has only be extracted for the `custom_particles`.
> If you'd like to compare all probability densities, just add its extraction to the `post`
> function for all particle equations and run again the post processing (do not forget to delete
> the `post_process/time` directory before).

You may note that the histogram is not converged, to obtain converged statistics, you may need to
run longer simulation with a higher number of particles. 

## Custom flow

**TODO**: Talk about choosing the flow
**TODO**: Talk about changing to 3D
**TODO**: Talk about writing your own flow

## Next tutorial

That's the end of this tutorial. 
In the next tutorial [02-parametric-study.md](02-parametric-study.md), 
you'll learn how to perform easily a parametric study through the example case of the **surfing strategy**.


