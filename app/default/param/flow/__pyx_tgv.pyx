cimport c0p
cimport std

# Parameters: initialize global parameters
cdef public void flow_parameters() noexcept nogil:
	pass

# Get Velocity: stores in u the flow velocity at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   u: the flow velocity at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceVector& u) noexcept nogil:
	u[0] = std.cos(x[0]) * std.sin(x[1])
	u[1] = -std.sin(x[0]) * std.cos(x[1])

# Get Velocity Gradients: stores in j the flow velocity gradients at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   j: the flow velocity gradients at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceMatrix& j) noexcept nogil:
	(&( j(0, 0) ))[0] = -std.sin(x[0]) * std.sin(x[1]); (&( j(0, 1) ))[0] = std.cos(x[0]) * std.cos(x[1]);
	(&( j(1, 0) ))[0] = -std.cos(x[0]) * std.cos(x[1]); (&( j(1, 1) ))[0] = std.sin(x[0]) * std.sin(x[1]);
