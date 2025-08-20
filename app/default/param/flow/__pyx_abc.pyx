cimport c0p
cimport std

# parameters
cdef double A, B, C

# Parameters: initialize global parameters
cdef public void flow_parameters() noexcept nogil:
	global A, B, C
	A, B, C = 1.0, 1.0, 1.0

# Get Velocity: stores in u the flow velocity at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   u: the flow velocity at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceVector& u) noexcept nogil:
	u[0] = A * std.sin(x[2]) + C * std.cos(x[1])
	u[1] = B * std.sin(x[0]) + C * std.cos(x[2])
	u[2] = C * std.sin(x[1]) + C * std.cos(x[0])

# Get Velocity Gradients: stores in j the flow velocity gradients at position x and time t.
# input:
#   x: particle position
#   t: current time
# output:
#   j: the flow velocity gradients at position x and time t
cdef public void flow_get_velocity(c0p.tViewConstSpaceVector x, const double t, c0p.tSpaceMatrix& j) noexcept nogil:
	(&( j(0, 0) ))[0] = 0.0;                (&( j(0, 1) ))[0] = C * -std.sin(x[1]); (&( j(0, 2) ))[0] = A * std.cos(x[2]);
	(&( j(1, 0) ))[0] = B * std.cos(x[0]);  (&( j(1, 1) ))[0] = 0.0;                (&( j(1, 2) ))[0] = A * -std.sin(x[2]);
	(&( j(2, 0) ))[0] = B * -std.sin(x[0]); (&( j(2, 1) ))[0] = C * std.cos(x[1]);  (&( j(2, 2) ))[0] = 0.0;
