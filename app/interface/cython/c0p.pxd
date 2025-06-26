
# Eigen

cdef extern from "param/parameters.h" namespace "c0p":
	cdef cppclass tSpaceVector:
		# constructor
		@staticmethod
		tSpaceVector Random() nogil
		@staticmethod
		tSpaceVector Zero() nogil
		# operators
		double operator[](const int) nogil
		double operator*(const double) nogil
		tSpaceVector& operator=(const tSpaceVector&) nogil
		# methods
		double* data() nogil
		unsigned int size() nogil

cdef extern from "core/prop.h" namespace "c0p":
	cdef cppclass tViewConstSpaceVector "const c0p::tView<const c0p::tSpaceVector>":
		# constructor
		tViewConstSpaceVector(const double*) nogil
		# operators
		double operator[](const int) nogil
		double operator*(const double) nogil
		# methods
		double* data() nogil
		unsigned int size() nogil

cdef extern from "core/prop.h" namespace "c0p":
	cdef cppclass tViewSpaceVector "c0p::tView<c0p::tSpaceVector>":
		# constructor
		tViewSpaceVector(double*) nogil
		# static
		@staticmethod
		unsigned int size() nogil
		# operators
		double operator[](const int) nogil
		double operator*(const double) nogil
		tViewSpaceVector& operator=(const tSpaceVector&) nogil
		# methods
		double* data() nogil
		unsigned int size() nogil

# Flow

cdef extern from "param/flow/parameters.h" namespace "c0p":
	cdef cppclass Flow:
		@staticmethod
		tSpaceVector getVelocity(const double* state, const double t) nogil
