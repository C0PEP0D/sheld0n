cimport c0p
cimport std

# parameters
cdef double stiffness
cdef double swimming_velocity
cdef double mass
cdef c0p.tSpaceVector z

cdef c0p.tMatrixDynamic m, g, k, mm, ma, v

# Parameters: initialize global parameters
cdef public void passive_particles_parameters() noexcept nogil:
	global stiffness, swimming_velocity, mass, z
	global m, g, k, mm, ma, v

	stiffness = 1e0
	swimming_velocity = 1.0
	mass = 1e1
	z = c0p.tSpaceVector(0.0, 1.0)

	m.resize(4, 6)
	c0p.set(m, 
		"""
		 0.01560997,  0.        ,  0.04012385, -0.04988129,  0.        , -0.3823366,
		 0.05354945,  0.        ,  0.05096943,  0.15440017,  0.        ,  0.2504946,
		 0.        ,  0.07035413,  0.        ,  0.        ,  0.07035413,  0.        ,
		-0.01666822,  0.        ,  0.05202767,  0.10085071,  0.        ,  0.31399268
		"""
	)

	g.resize(4, 2)
	c0p.set(g, 
		"""
		 0.       ,   0.43664202,
		 0.       ,   0.45780975,
		-0.9670445,   0.        ,
		 0.       ,  -0.50985384
		"""
	)

	cdef c0p.tMatrixDynamic x

	x.resize(6, 1)
	c0p.set(x,
		"""
		 0.,
		 0.,
		-1.,
		 0.,
		 0.,
		 1.
		"""
	)

	k = m * x

	x.resize(6, 2)
	c0p.set(x,
		"""
		 1.,  0.,
		 0.,  1.,
		 0.,  0.,
		-1.,  0.,
		 0., -1.,
		 0.,  0.
		"""
	)

	mm = m * x

	x.resize(6, 2)
	c0p.set(x,
		"""
		0., 0.,
		0., 0.,
		0., 0.,
		1., 0.,
		0., 1.,
		0., 0.
		"""
	)

	ma = m * x

	v.resize(4, 3)
	c0p.set(v,
		"""
		0., 0., 0.,
		1., 0., 0.,
		0., 1., 0.,
		0., 0., 1.,
		"""
	)
	
# Constrain: constrain the state variable if necessary (normalize unit vectors for instance)
# input:
#   t: current time
# input and output:
#   x: particle position
cdef public void passive_particles_constrain(const double t, c0p.tViewSpaceVector x, double& theta, double& dof) noexcept nogil:
	pass

# Prepare: prepare the flow to be processed (mostly used for the Johns Hopkins Database).
# State in this function if you intend to use the flow velocity and the flow velocity gradients in the state_temporal_derivative function.
# input:
#   x: particle position
#   t: current time
cdef public void passive_particles_prepare(c0p.tViewConstSpaceVector x, const double theta, const double dof, const double t) noexcept nogil:
	c0p.Flow.prepareVelocity(x.data(), t)
	c0p.Flow.prepareVelocityGradients(x.data(), t)

# State Temporal Derivative: describe the temporal derivative of your state variable.
# input:
#   x: particle position
#   t: current time
# output:
#   dx: dx/dt, temporal derivative of the particle position
cdef public void passive_particles_state_temporal_derivative(c0p.tViewConstSpaceVector x, const double theta, const double dof, const double t, c0p.tViewSpaceVector dx, double& dtheta, double& ddof) noexcept nogil:
	# get flow velocity at position x and time t
	cdef c0p.tSpaceVector u = c0p.Flow.getVelocity(x.data(), t)
	cdef c0p.tSpaceMatrix grad_u = c0p.Flow.getVelocityGradients(x.data(), t)
	# flow velocity gradients
	cdef c0p.tSpaceMatrix sym_grad_u = 0.5 * (grad_u + grad_u.transpose())
	cdef c0p.tSpaceMatrix skew_grad_u = 0.5 * (grad_u - grad_u.transpose())
	cdef double omega = skew_grad_u(1, 0)
	# orientation
	cdef std.string sep = std.string(", ")
	cdef c0p.tSpaceMatrix r
	c0p.set(r, (
		std.to_string( std.cos(theta) ) + sep + std.to_string( -std.sin(theta) ) + sep +
		std.to_string( std.sin(theta) ) + sep + std.to_string(  std.cos(theta) )
	).c_str())
	# u inf
	cdef c0p.tMatrixDynamic u_inf
	u_inf.resize(3, 1)
	c0p.set(u_inf, (
		std.string(
			"""
			0.0,
			0.0,
			"""
		) + std.to_string(omega)
	).c_str())
	# s par
	cdef c0p.tSpaceMatrix s_par = r.transpose() * sym_grad_u * r
	# s inf
	cdef c0p.tSpaceVector s_inf = c0p.tSpaceVector(
		s_par(0, 0), 
		s_par(0, 1)
	);
	# z hat
	cdef c0p.tSpaceVector z_hat = r.transpose() * z
	# f act
	cdef c0p.tSpaceVector f_act = c0p.tSpaceVector(
		std.sin(4.0 * dof), 
		std.cos(4.0 * dof)
	)
	# activ
	cdef double activ = swimming_velocity / (ma.block(1, 0, 3, 2) * f_act).norm()

	cdef c0p.tMatrixDynamic deriv = stiffness * k * dof + mass * mm * z_hat + activ * ma * f_act + v * u_inf + g * s_inf

	cdef c0p.tSpaceVector p = c0p.tSpaceVector(
		-std.sin(theta - 0.0 * 4.0 * dof), 
		std.cos(theta - 0.0 * 4.0 * dof)
	)

	dx = u + swimming_velocity * p
	dtheta = deriv(deriv.size() - 1, 0)
	ddof = deriv(0, 0)

# Init: initialize your state variable.
# input:
#   particle_number: number of particle
# output:
#   x_array: array of particle position
cdef public void passive_particles_init(const unsigned int particle_number, c0p.tViewSpaceVector* x_array, double** theta_array, double** dof_array) noexcept nogil:
	# set random initial positions to all particles
	cdef int particle_index, state_index
	for particle_index in range(int(particle_number)):
		x_array[particle_index] = c0p.tSpaceVector.Random() * std.M_PI
		theta_array[particle_index][0] = c0p.tSpaceVector.Random()[0] * std.M_PI
		dof_array[particle_index][0] = c0p.tSpaceVector.Random()[0]

# Post: post process data.
# input:
#   x_array: array of particle position
#   particle_number: number of particle
#   t: current time
# output:
#   output_dictionary: dictionary that contains the post processed data
cdef public void passive_particles_post(c0p.tViewConstSpaceVector* x_array, double* theta_array, double* dof_array, const unsigned int particle_number, const double t, std.map[std.string, double]& output_dictionary) noexcept nogil:
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
		n_surf = c0p.tSpaceVector.Zero()
		
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
