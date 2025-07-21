cimport c0p
cimport std

# parameters
cdef double swimming_velocity = 1.0

cdef double aspect_ratio = 1.0 # aspect ratio of the spheroidal particles
cdef double factor = (aspect_ratio * aspect_ratio - 1.0) / (aspect_ratio * aspect_ratio + 1.0) # factor used in the equation

# Constrain: constrain the state variable if necessary (normalize unit vectors for instance)
# input:
#   t: current time
# input and output:
#   x: particle position
#   p: particle swimming direction
cdef public void passive_particles_constrain(const double t, c0p.tViewSpaceVector x, c0p.tViewSpaceVector p) noexcept nogil:
	p = p.normalized()

# Prepare: prepare the flow to be processed (mostly used for the Johns Hopkins Database).
# State in this function if you intend to use the flow velocity and the flow velocity gradients in the state_temporal_derivative function.
# input:
#   x: particle position
#   p: particle swimming direction
#   t: current time
cdef public void passive_particles_prepare(c0p.tViewConstSpaceVector x, c0p.tViewConstSpaceVector p, const double t) noexcept nogil:
	c0p.Flow.prepareVelocity(x.data(), t)
	c0p.Flow.prepareVelocityGradients(x.data(), t)

# State Temporal Derivative: describe the temporal derivative of your state variable.
# input:
#   x: particle position
#   p: particle swimming direction
#   t: current time
# output:
#   dx: dx/dt, temporal derivative of the particle position
#   dp: dp/dt, temporal derivative of the particle swimming direction
cdef public void passive_particles_state_temporal_derivative(c0p.tViewConstSpaceVector x, c0p.tViewConstSpaceVector p, const double t, c0p.tViewSpaceVector dx, c0p.tViewSpaceVector dp) noexcept nogil:
	# get flow velocity at position x and time t
	cdef c0p.tSpaceVector u = c0p.Flow.getVelocity(x.data(), t)
	cdef c0p.tSpaceMatrix grad_u = c0p.Flow.getVelocityGradients(x.data(), t)

	cdef c0p.tSpaceMatrix sym_grad_u = 0.5 * (grad_u + grad_u.transpose())
	cdef c0p.tSpaceMatrix skew_grad_u = 0.5 * (grad_u - grad_u.transpose())
	
	# set the temporal derivative of x as the flow velocity
	dx = u + swimming_velocity * p.normalized()
	dp = skew_grad_u * p  + factor * (sym_grad_u * p - p.dot(sym_grad_u * p) * p)

# Init: initialize your state variable.
# input:
#   particle_number: number of particle
# output:
#   x_array: array of particle position
cdef public void passive_particles_init(const unsigned int particle_number, c0p.tViewSpaceVector* x_array, c0p.tViewSpaceVector* p_array) noexcept nogil:
	# set random initial positions to all particles
	cdef int particle_index, state_index
	for particle_index in range(int(particle_number)):
		x_array[particle_index] = c0p.tSpaceVector.Random() * std.M_PI
		p_array[particle_index] = c0p.tSpaceVector.Random().normalized()

# Post: post process data.
# input:
#   x_array: array of particle position
#   particle_number: number of particle
#   t: current time
# output:
#   output_dictionary: dictionary that contains the post processed data
cdef public void passive_particles_post(c0p.tViewConstSpaceVector* x_array, c0p.tViewConstSpaceVector* p_array, const unsigned int particle_number, const double t, std.map[std.string, double]& output_dictionary) noexcept nogil:
	# extract format number
	cdef int format_particle_number = std.log10(particle_number)
	cdef int format_particle_index
	cdef int particle_index, dim_index, key_index
	cdef std.string key

	# post process the position of each particle, and compute average position
	cdef c0p.tSpaceVector x_average = c0p.tSpaceVector.Zero()
	cdef c0p.tSpaceVector p_average = c0p.tSpaceVector.Zero()

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

		# swimming direction
		for dim_index in range(x_array[particle_index].size()):
			# zero padding
			key = std.string('passive_particles__index_')
			for key_index in range(format_particle_number - format_particle_index):
				key += std.string('0')
			key += std.to_string(particle_index)
			key += std.string('__p_')
			key += std.to_string(dim_index)
		
		# add position to average
		x_average += x_array[particle_index]
		p_average += p_array[particle_index]

	# end computation of average
	x_average /= particle_number
	p_average /= particle_number

	# store average in output dictionary

	## position
	for dim_index in range(x_average.size()):
		# zero padding
		key = std.string('passive_particles__average_pos_')
		key += std.to_string(dim_index)
		output_dictionary[key] = x_average[dim_index]

	## swimming direction
	for dim_index in range(x_average.size()):
		# zero padding
		key = std.string('passive_particles__average_p_')
		key += std.to_string(dim_index)
		output_dictionary[key] = x_average[dim_index]
