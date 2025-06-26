
from libc.stdlib cimport rand, RAND_MAX
from libc.math cimport M_PI

from libcpp.map cimport map as map
from libcpp.string cimport string as string

cdef extern from "<string>" namespace "std":
	string to_string(int) nogil

cdef extern from "<cmath>" namespace "std":
	int log10(int) nogil
