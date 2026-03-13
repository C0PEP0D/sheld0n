cimport c0p

# Flow

cdef extern from "param/flow/parameters.h" namespace "c0p":
	cdef cppclass Flow:

		@staticmethod
		void prepareVelocity(const double* pX, const double t) nogil
		@staticmethod
		void prepareVelocityGradients(const double* pX, const double t) nogil
	
		@staticmethod
		c0p.tSpaceVector getVelocity(const double* pX, const double t) nogil
		@staticmethod
		c0p.tSpaceMatrix getVelocityGradients(const double* pX, const double t) nogil
