# Writing your own equations

Here you'll learn how to customize particles and flows to encode your own equations into the code
using the **Cython** interface.

## Table of Contents

- [Writing in Cython](#writing-in-cython)
- [Custom particle equation](#custom-particle-equation)
- [Custom post processing](#custom-post-processing)
- [Custom flow equation](#custom-flow-equation)
- [Next tutorial](#next-tutorial)

## Writing in Cython

In this code, most parameters are defined directly in **C++** and can be accessed by the user to change simulation parameters.
To help with the creation of new custom equations, the code provides a flexible **C++** interface that let you encode almost anything
or an easier to use **Cython** interface slightly less flexible.

If you need more flexibility and slightly better simulation performance, the next tutorial will transpose what you will learn here 
into directly editing **C++** parameter files for more flexibility.

First let's generate a new case to avoid breaking the first tutorial case.
Rather than generating a new case from scratch, let's just copy our first case.

```
Copy you first case case-00 as case-01.
```

Before doing anything, let's clean everything inside this new case.

```
Move into the case-01 directory and execute both the clean_build and the clean_time scripts.
```

## Custom particle equation

As an exercise, let us now try to create a particle that is both buoyant and inertial.
The motion of such a particle would be described by the following equations
```math
\frac{d \vec{x}}{dt} = \vec{v}
```
```math
\frac{d \vec{v}}{dt} = \frac{ u \left ( \vec{x}, t \right ) + V_{\mathrm{buoyancy}} \vec{z} - \vec{v} }{\tau} \, \mathrm{.}
```

While this equation is not included in the choices available in the solver, `pyx_buoyant_particles` and 
`pyx_inertial_particles` are both already available.
By merging together both behavior, we should be fine.

Let's first start by adding a new custom particle equation based on **pyx_buoyant_particles**.
```
Move to the param/solutions directory and execute the *_create_new_equation script.
Give the name custom_particles to your new equation and choose **pyx_buoyant_particles**.
```

Let's just copy the `parameters_custom_particles.pyx` for buoyant particles and save it to have access to it later.
```
Move to the custom_particles directory.
Copy parameters_custom_particles.pyx into parameters_buoyant_saved.pyx.
```

Let's now start our new custom behavior based on that of inertial particles.
```
Execute the choose script and choose the **pyx_inertial_particles**.
```

We can now open both file at the same time and try to merge the `parameters_buoyant_saved.pyx` file into the `parameters_custom_particles.pyx` file.
Let us first copy paste the buoyancy parameters into our parameters.
```cython
# parameters
cdef double reaction_time
cdef double buoyant_velocity # <--- ADDED
cdef c0p.tSpaceVector buoyancy_direction # <--- ADDED

# Parameters: initialize global parameters
cdef public void buoyant_particles_parameters() noexcept nogil:
	global reaction_time, buoyant_velocity, buoyancy_direction # <--- CHANGED

	buoyant_velocity = 0.5 # <--- ADDED
	buoyancy_direction = c0p.tSpaceVector(0.0, 1.0) # <--- ADDED
```

Then we need to modify the definition of the temporal derivative of our state variables to match the previous equation.

```cython
cdef public void custom_particles_state_temporal_derivative(c0p.tViewConstSpaceVector x, c0p.tViewConstSpaceVector v, const double t, c0p.tViewSpaceVector dx, c0p.tViewSpaceVector dv) noexcept nogil:
	# get flow velocity at position x and time t
	cdef c0p.tSpaceVector u = c0p.Flow.getVelocity(x.data(), t)
	# set the temporal derivative of x as the flow velocity
	dx = v
	dv = (u + buoyant_velocity * buoyancy_direction - v) / reaction_time # <--- CHANGED
```

Congrats ! You implemented your first custom equation into the solver.
The code should already be able to run and solve your equation,
but before moving on, let's try to edit the `init` function too.

Starting with the `init`, it might make more sense to initialize the velocity of particles to their buoyant velocity rather than to the flow velocity.
```cython
cdef public void custom_particles_init(const unsigned int particle_number, c0p.tViewSpaceVector* x_array, c0p.tViewSpaceVector* v_array) noexcept nogil:
	# set random initial positions to all particles
	cdef int particle_index, state_index
	for particle_index in range(int(particle_number)):
		x_array[particle_index] = c0p.tSpaceVector.Random() * std.M_PI
		v_array[particle_index] = buoyant_velocity * buoyancy_direction # <--- CHANGED
```

One could similarly change the `post` function too to match your needs.
Once everything is setup, we can run the simulation and the post processing.
```
Move back to the case-01 directory.
And execute the *_run script.
```

Finally you can see your own custom particles in action.
```
Move to the post_process directory and run the generate_trajectory_animation.py script (again, it may take a while).
```

## Custom post processing

We could directly use the Python scripts available to plot trajectories or vertical displacement over time of all our particles.
These scripts focus on the position of particles extracted from the simulation.
However, we also extract the velocity of these particles.

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

We are now interested by the particle velocity of our particles.
Therefore let's change the first part to read the particle velocity rather than the vertical position.
```python
33	print("INFO: Reading equation property over time...", flush=True)
34	v_0_over_time = {}
35	v_1_over_time = {}
36	for equation_name in equation_name_list:
37		v_0_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__v_0", time_dir_array))
38		v_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__v_1", time_dir_array))
```

Now for the plot, plotting this velocity over time would have little interest.
We can rather use the `plt.hist` function to plot the probability function of the particle velocity.
To do that change the next part to the following.
```python
39	print("INFO: Plotting property difference to initial time average ...", flush=True)
40	for equation_index, equation_name in enumerate(equation_name_list):
41		plt.hist(v_1_over_time[equation_name].flatten(), bins=32, density=True, histtype="stepfilled", color=color_list[equation_index], label=equation_name)
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
> the particle velocity has only be extracted for the `custom_particles`.
> If you'd like to compare all probability densities, just add its extraction to the `post`
> function for all particle equations and run again the post processing (do not forget to delete
> the `post_process/time` directory before).

You may note that the histogram is not converged, to obtain converged statistics, you may need to
run longer simulation with a higher number of particles.

## Custom flow equation

Similarly a python flow can be chosen in the `param/flow` directory and the `parameters.py` file edited to modify its behavior.
If you do so, the flow can be directly accessed in **Python** parameter files as follows:

 ```python
sys.path.append('param')
import flow.parameters as flow

u = flow.get_velocity(x, t) # get flow velocity
 ```

## Next tutorial

That's the end of this tutorial. 

In the next tutorial [02-custom-cpp-equations.md](02-custom-cpp-equations.md), 
you'll learn how to basically do the same using **C++** to avoid the performance drop caused
by the **Python** interface.
