cimport c0p
cimport std

# parameters
cdef c0p.tSpaceVector u_0 # flow velocity at position (0, 0) and time t = 0.0
cdef c0p.tSpaceMatrix grad # flow velocity gradients
cdef c0p.tSpaceVector a # flow acceleration

# Parameters: initialize global parameters
cdef public void flow_parameters() noexcept nogil:
	global u_0, grad, a
	# u_0
	u_0[0] = 0.0
	u_0[1] = 0.0
	u_0[2] = 0.0
	# grad
	(&( j(0, 0) ))[0] = 0.0;  (&( j(0, 1) ))[0] = 1.0;  (&( j(0, 2) ))[0] = -1.0;
	(&( j(1, 0) ))[0] = 1.0;  (&( j(1, 1) ))[0] = -1.0; (&( j(1, 2) ))[0] = 1.0;
	(&( j(2, 0) ))[0] = -1.0; (&( j(2, 1) ))[0] = -1.0; (&( j(2, 2) ))[0] = 1.0;
	# a
	a[0] = 0.0;
	a[1] = 0.0;
	a[2] = 0.0;

# Get Velocity: stores in u the flow velocity at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   u: the flow velocity at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceVector& u) noexcept nogil:
	u = u_0 + grad * x + a * t

# Get Velocity Gradients: stores in j the flow velocity gradients at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   j: the flow velocity gradients at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceMatrix& j) noexcept nogil:
	j = grad;
