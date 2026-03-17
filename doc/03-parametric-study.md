# Adding new particles to the simulation

Welcome to the tutorial series that will teach you how to use the `sheld0n` code.

## Table of Contents

- [The surfing strategy](#writting-in-c++)
- [Creating a batch of particles](#creating-a-batch-of-surfers)
- [Post processing](#post-processing)

## The surfing strategy

This code has originally been developed to assess the performance of the **Surfing** strategy described in the 
[Surfing on Turbulence](https://journals.aps.org/prl/abstract/10.1103/PhysRevLett.129.064502) paper.

The paper is freely available via [CHORUS](https://link.aps.org/accepted/10.1103/PhysRevLett.129.064502).
For a more complete understanding of this strategy and the navigation problem at hand, one may also refer to this [Ph.D. thesis](https://github.com/rmonthil-phd/thesis-a-mechanistic-approach-to-plakton-migration/releases/download/v1.0-comments-addressed/thesis_a_mechanistic_approach_to_plankton_migration_v1.pdf).
If you prefer a video explanation, feel free to view the following Ph.D. defense.

[![YouTube](http://i.ytimg.com/vi/LDYkYfR8kcw/hqdefault.jpg)](https://www.youtube.com/watch?v=LDYkYfR8kcw)

As an example of a parametric study that can be performed using this code, we will try to replicate the Figure 3a of the paper.
Rather than using a turbulent flow, we will use Taylor-Green vortices for shorter simulation times.

The surfing strategy involves a free parameter $\tau$ representing a time horizon for which the flow velocity gradients 
$\vec{\nabla} \vec{u}$ can be considered constant.
This parameter has an optimal value $\tau^{*}$ that needs to be assessed numerically.

*A priori*, the value of this optimal parameter depends on both the flow itself (which won't be changed here) and the swimming 
speed $V_{\mathrm{swim}}$ of the swimmer. Therefore a parametric study of performance is necessary to study the evolution of this
optimal time horizon $\tau^{*}$ as a function of the swimming speed.

To perform this parametric study, the script `param/solutions/batch_copy_equation` will be essential. 

## Creating a batch of surfers

Let's first create a new case.
```
Move to the cases directory.
Execute the generate_new_case script and create a new case named case_03.
Move to the newly created case_03 directory.
```
We can then add some surfers into it.
```
Move to the params/solutions directory.
Execute the create_new_equation script with the name surfers and choose cpp_surfers.
```
Feel free to open and look at the `parameters.h` file to see how the surfing strategy is implemented.
By default the swimming velocity is set to `0.5` and the time horizon to `0.5` too.

These values are good enough however we would like to explore various values of these parameters.
And here comes the `batch_copy_equation` script to help us.
```sh
Execute the batch_copy_equation script.
Specify surfers as the sources.
Specify TimeHorizon as the property.
Specify 0.0 0.25 0.5 0.75 1.0 1.25 1.5 1.75 2.0 as values.
Leave the factor field empty.
```
The commands states to copy the **surfers** and in each copy, to change the parameter (`-p`) **TimeHorizon** with a value among (`-v`) **0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0**.
Checkout the content of the solutions directory now and you'll see a bunch of new directories corresponding to just that.

You can make sure that the parameter `TimeHorizon` has correctly been change in their `parameters.h` files.

We won't be needing the original `surfers` so let's just remove them from the simulation.
```sh
Execute the remove_equation script and specify the surfers.
```
> [!CAUTION]
> Make sure to use the `remove_equation` script to remove particles rather than manually deleting the directory, otherwise you might corrupt the `param/solutions/parameters.h` file.

Once this is done, one can then use again the `batch_copy_equation` to vary the **SwimmingVelocity** parameter.

```
Execute the batch_copy_equation script.
Use surfers__* as source.
Use SwimmingVelocity as property.
Use 0.25 0.5 1.0 as values.
```

Again, you'll see a whole lot more surfers appear as the swimming speed has been changed for each value of the time horizon.
Similarly, we can now delete the original surfers as they won't be needed anymore.

```
Execute the remove_equation script.
Use surfers__TimeHorizon_0o00 surfers__TimeHorizon_0o25 surfers__TimeHorizon_0o50 surfers__TimeHorizon_0o75 surfers__TimeHorizon_1o00 surfers__TimeHorizon_1o25 surfers__TimeHorizon_1o50 surfers__TimeHorizon_1o75 surfers__TimeHorizon_2o00 as equations.
```

It is now time to run the simulation.
```
Move back to the root case and execute the run script.
```
We can then get to the post processing to see the results.
```
Move to the post_process directory.
```

Rather than including all particles in our trajectory animation, we would like to focus on passive_particles and two specific time horizons at $V_{\mathrm{swim}} = 0.5$.

To do so open the `generate_trajectory_animation_2d.py` and define the equations to be post processed as follows:

```python
default_equation_list = [passive_particles, surfers__TimeHorizon_0o00__SwimmingVelocity_0o50, surfers__TimeHorizon_0o50__SwimmingVelocity_0o50]
```
You can then generate the animation by executing the `run_post_process` script.

## Post processing

Now that we saw that the simulation did work, let's focus now on the plot we need to do to replicate the figure 3a of the *Surfing on Turbulence* paper.
Let's first copy the example script and start from there.
```sh
cp plot_over_time.py plot_performance_f_time_horizon.py
```
We can then open `plot_performance_f_time_horizon.py` and start editing it to our needs.
Let's first adapt the main function to the following
```python
def main(input_equation_list, input_color_list):
    # equations
    if input_equation_list:
        equation_name_list = input_equation_list
    else:
        print("INFO: Reading equation names...", flush=True)
        equation_name_list = libpost.get_equation_names()
    print("INFO: Reading time...", flush=True)
    time_dir_array, time_array = libpost.get_time()
    print("INFO: Reading equation property over time...", flush=True)
    pos_1_over_time = {}
    for equation_name in equation_name_list:
        pos_1_over_time[equation_name] = np.array(libpost.get_equation_property_over_time(equation_name, ".*__pos_1", time_dir_array))
    print("INFO: Computing the vertical migration performance...", flush=True)
    average_performance = {}
    for equation_name in equation_name_list:
        average_performance[equation_name] = (pos_1_over_time[equation_name][-1] - pos_1_over_time[equation_name][0]).mean() / (8.0 * np.pi) # (8.0 * np.pi) corresponds to the duration of the simulation, change it if our edited the param/run/parameters.h file
```
The beginning of the function is the same as before but we removed the plots and added a new section that computes the average vertical migration
performance of each *surfer group* computed as the average vertical migration speed.

We now have almost everything to plot our figure, the last thing we need is to recover the parameters of the surfers. 
This can be done using their names generated using the `batch_copy_equation` scripts.
Fortunately the function `get_properties_from_string` provided by the `libpost` module can be used just for that.

You can add the following to the script to extract these parameters and restructure the data for the plot.
```python
    print("INFO: Extracting parameters from equation names...", flush=True)
    average_performance_sorted = {}
    for equation_name in equation_name_list:
        parameters = libpost.get_properties_from_string(equation_name)
        if "TimeHorizon" in parameters and "SwimmingVelocity" in parameters:
            if not parameters["SwimmingVelocity"] in average_performance_sorted:
                average_performance_sorted[parameters["SwimmingVelocity"]] = [[parameters["TimeHorizon"], average_performance[equation_name]]]
            else:
                average_performance_sorted[parameters["SwimmingVelocity"]].append([parameters["TimeHorizon"], average_performance[equation_name]])
    for swimming_velocity in average_performance_sorted:
        average_performance_sorted[swimming_velocity] = np.array(average_performance_sorted[swimming_velocity])
        average_performance_sorted[swimming_velocity] = average_performance_sorted[swimming_velocity][average_performance_sorted[swimming_velocity][:, 0].argsort()]
```

Finally one can add the plot itself.
```python
    print("INFO: Plotting...", flush=True)
    # colors
    if input_color_list:
        color_list = input_color_list
    else:
        cmap = plt.get_cmap("plasma", len(average_performance_sorted))
        color_list = [cmap(index) for index in range(len(average_performance_sorted))]
    # plot
    color_index = 0
    for swimming_velocity in sorted(average_performance_sorted):
        plt.plot(average_performance_sorted[swimming_velocity][:, 0], average_performance_sorted[swimming_velocity][:, 1] / swimming_velocity, color=color_list[color_index], label=r'$V_{\mathrm{swim}} = ' + str(swimming_velocity) + r'$')
        color_index += 1
    plt.xlabel(r'$\tau$')
    plt.ylabel(r'$\langle V_{\mathrm{eff.}} \rangle / V_{\mathrm{swim}}$')
    plt.legend()
    plt.show()
```
You should then be able to plot it and observe the results.
In particular for the smallest swimming velocity, you may notice that the results did not statistically converge.

If you'd like to obtain converge results, you'll have to increase the number of particles in your simulation.
To do so, you may just increase the value of the `cGroupSize` parameter in he `param/parameters.h` file.

You can then run again the simulation and seen how the results change.

> [!NOTE]
> Make sure to clean the simulation before running it again using the `clean_time` script.

## Next tutorial

That's the end of this tutorial. 
In the next tutorial [04-reinforcement-learning.md](04-reinforcement-learning.md), 
you'll learn how to use basic reinforcement learning to solve a navigation problem.
