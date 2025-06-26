cimport c0p
cimport std

# input:
#   state: particle state variable (position) as a numpy array
#   u: flow velocity at the particle position as a numpy array
# output:
#   dstate: temporal derivative of the particle state variable (its velocity in this case)
cdef public void passive_particles_state_temporal_derivative(c0p.tViewConstSpaceVector x, const double t, c0p.tViewSpaceVector dx) noexcept nogil:
	# get flow velocity at position x and time t
	cdef c0p.tSpaceVector u = c0p.Flow.getVelocity(x.data(), t)
	# set the temporal derivative of x as the flow velocity
	dx = u

# input:
#   particle_state_size: dimension of the state variable of one particle
#   particle_number: number of particle
# output:
#   initial particle state
cdef public void passive_particles_init(const unsigned int particle_number, c0p.tViewSpaceVector* x_array) noexcept nogil:
	# set random initial positions to all particles
	cdef int particle_index, state_index
	for particle_index in range(int(particle_number)):
		x_array[particle_index] = c0p.tSpaceVector.Random() * std.M_PI

# input:
#   state: state variable that groups the state variables of all particles
#   particle_state_size: dimension of the state variable of one particle
#   particle_number: number of particle
# output:
#   dictionary that contains the post processed data
cdef public void passive_particles_post(c0p.tViewConstSpaceVector* x_array, const unsigned int particle_number, const double t, std.map[std.string, double]& output_dictionary) noexcept nogil:
	# extract format number
	cdef int format_particle_number = std.log10(particle_number)
	cdef int format_particle_index
	cdef int particle_index, dim_index, key_index
	cdef std.string key
	# post process the position of each particle, and compute average position
	cdef c0p.tSpaceVector x_average = c0p.tSpaceVector.Zero()
	for particle_index in range(particle_number):
		format_particle_index = std.log10(particle_index)
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
