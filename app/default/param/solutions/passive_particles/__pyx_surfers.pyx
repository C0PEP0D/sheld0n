cimport c0p
cimport std

# parameters
cdef c0p.tSpaceVector target_direction = c0p.tSpaceVector(1.0, 0.0)
cdef const double swimming_velocity = 1.0
cdef const double time_horizon = 1.0

# Constrain: constrain the state variable if necessary (normalize unit vectors for instance)
# input:
#   t: current time
# input and output:
#   x: particle position
cdef public void passive_particles_constrain(const double t, c0p.tViewSpaceVector x) noexcept nogil:
	pass

# Prepare: prepare the flow to be processed (mostly used for the Johns Hopkins Database).
# State in this function if you intend to use the flow velocity and the flow velocity gradients in the state_temporal_derivative function.
# input:
#   x: particle position
#   t: current time
cdef public void passive_particles_prepare(c0p.tViewConstSpaceVector x, const double t) noexcept nogil:
	c0p.Flow.prepareVelocity(x.data(), t)
	c0p.Flow.prepareVelocityGradients(x.data(), t)

# State Temporal Derivative: describe the temporal derivative of your state variable.
# input:
#   x: particle position
#   t: current time
# output:
#   dx: dx/dt, temporal derivative of the particle position
cdef public void passive_particles_state_temporal_derivative(c0p.tViewConstSpaceVector x, const double t, c0p.tViewSpaceVector dx) noexcept nogil:
	# get flow velocity at position x and time t
	cdef c0p.tSpaceVector u = c0p.Flow.getVelocity(x.data(), t)
	cdef c0p.tSpaceMatrix grad_u = c0p.Flow.getVelocityGradients(x.data(), t)
	# compute surfing direction
	cdef c0p.tSpaceVector n_surf = ((grad_u * time_horizon).exp().transpose() * target_direction).normalized()
	# set the temporal derivative of x as the flow velocity
	dx = u + swimming_velocity * n_surf

# Init: initialize your state variable.
# input:
#   particle_number: number of particle
# output:
#   x_array: array of particle position
cdef public void passive_particles_init(const unsigned int particle_number, c0p.tViewSpaceVector* x_array) noexcept nogil:
	# set random initial positions to all particles
	cdef int particle_index, state_index
	for particle_index in range(int(particle_number)):
		x_array[particle_index] = c0p.tSpaceVector.Random() * std.M_PI

# Post: post process data.
# input:
#   x_array: array of particle position
#   particle_number: number of particle
#   t: current time
# output:
#   output_dictionary: dictionary that contains the post processed data
cdef public void passive_particles_post(c0p.tViewConstSpaceVector* x_array, const unsigned int particle_number, const double t, std.map[std.string, double]& output_dictionary) noexcept nogil:
	# extract format number
	cdef int format_particle_number = std.log10(particle_number)
	cdef int format_particle_index
	cdef int particle_index, dim_index, key_index
	cdef std.string key

	# n_surf computation utils
	cdef c0p.tSpaceVector u
	cdef c0p.tSpaceMatrix grad_u
	cdef c0p.tSpaceVector n_surf

	# post process the position of each particle, and compute average position
	cdef c0p.tSpaceVector x_average = c0p.tSpaceVector.Zero()

	for particle_index in range(particle_number):
		format_particle_index = std.log10(particle_index)

		# position
		for dim_index in range(x_array[particle_index].size()):
			# zero padding
			key = std.string('passive_particles__index_')
			for key_index in range(format_particle_number - format_particle_index):
				key += std.string('0')
			key += std.to_string(particle_index)
			key += std.string('__pos_')
			key += std.to_string(dim_index)
			# output
			output_dictionary[key] = x_array[particle_index][dim_index]

		# compute the surfing direction

		# surfing direction
		u = c0p.Flow.getVelocity(x_array[particle_index].data(), t)
		grad_u = c0p.Flow.getVelocityGradients(x_array[particle_index].data(), t)
		# compute surfing direction
		n_surf = ((grad_u * time_horizon).exp().transpose() * target_direction).normalized()
		
		for dim_index in range(x_array[particle_index].size()):
			# zero padding
			key = std.string('passive_particles__index_')
			for key_index in range(format_particle_number - format_particle_index):
				key += std.string('0')
			key += std.to_string(particle_index)
			key += std.string('__n_')
			key += std.to_string(dim_index)
			# output
			output_dictionary[key] = n_surf[dim_index]

		# add position to average
		x_average += x_array[particle_index]

	# end computation of average
	x_average /= particle_number

	# store average in output dictionary
	output_dictionary['passive_particles__average_pos_']
	for dim_index in range(x_average.size()):
		# zero padding
		key = std.string('passive_particles__average_pos_')
		key += std.to_string(dim_index)
		output_dictionary[key] = x_average[dim_index]
