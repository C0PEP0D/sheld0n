
# Eigen

cdef extern from "param/parameters.h" namespace "c0p":
	cdef cppclass tSpaceVector:
		# constructor

		## proper
		tSpaceVector() nogil
		tSpaceVector(const tSpaceVector&) nogil
		tSpaceVector(tViewConstSpaceVector&) nogil
		
		tSpaceVector(const double, const double) nogil # 2D
		tSpaceVector(const double, const double, const double) nogil # 3D

		## defaults
		@staticmethod
		tSpaceVector Random() nogil
		@staticmethod
		tSpaceVector Zero() nogil
		@staticmethod
		tSpaceVector Constant(const double) nogil

		# operators
		double operator[](const int) nogil
		double& operator[](const int) nogil
		
		tSpaceVector operator*(const double) nogil
		tSpaceVector operator*(const double, const tSpaceVector&) nogil
		tSpaceVector operator/(const double) nogil
		
		tSpaceVector operator+(const tSpaceVector&) nogil
		tSpaceVector operator-(const tSpaceVector&) nogil
		tSpaceVector& operator=(const tSpaceVector&) nogil
		
		tSpaceVector operator+(tViewConstSpaceVector&) nogil
		tSpaceVector operator-(tViewConstSpaceVector&) nogil
		tSpaceVector& operator=(tViewConstSpaceVector&) nogil

		# methods

		## maths
		double norm() nogil
		tSpaceVector normalized() nogil
		double dot(const tSpaceVector&) nogil
		double dot(tViewConstSpaceVector&) nogil

		## data
		double* data() nogil
		unsigned int size() nogil

cdef extern from "param/parameters.h" namespace "c0p":
	cdef cppclass tViewConstSpaceVector "const c0p::tView<const c0p::tSpaceVector>":
		# constructor
		tViewConstSpaceVector(const double*) nogil

		# operators
		double operator[](const int) nogil
		
		tSpaceVector operator*(const double) nogil
		tSpaceVector operator*(const double, tViewConstSpaceVector&) nogil
		tSpaceVector operator/(const double) nogil
		
		tSpaceVector operator+(const tSpaceVector&) nogil
		tSpaceVector operator-(const tSpaceVector&) nogil
		
		tSpaceVector operator+(tViewConstSpaceVector&) nogil
		tSpaceVector operator-(tViewConstSpaceVector&) nogil

		# methods

		## maths
		double norm() nogil
		tSpaceVector normalized() nogil
		double dot(const tSpaceVector&) nogil
		double dot(tViewConstSpaceVector&) nogil

		## data
		double* data() nogil
		unsigned int size() nogil

cdef extern from "<unsupported/Eigen/MatrixFunctions>":
	pass

cdef extern from "param/parameters.h" namespace "c0p":
	cdef cppclass tSpaceMatrix:
		# constructor
		## proper
		tSpaceMatrix() nogil
		## defaults
		@staticmethod
		tSpaceMatrix Random() nogil
		@staticmethod
		tSpaceMatrix Zero() nogil
		@staticmethod
		tSpaceMatrix Identity() nogil
		@staticmethod
		tSpaceVector Constant(const double) nogil
		# operators
		double operator[](const int) nogil
		double& operator[](const int) nogil

		double operator()(const int, const int) nogil
		double& operator()(const int, const int) nogil
		
		tSpaceMatrix operator*(const double) nogil
		tSpaceMatrix operator*(const double, const tSpaceMatrix&) nogil
		tSpaceMatrix operator/(const double) nogil

		tSpaceVector operator*(const tSpaceVector&) nogil

		tSpaceVector operator*(tViewConstSpaceVector&) nogil

		tSpaceMatrix operator*(const tSpaceMatrix&) nogil
		tSpaceMatrix operator+(const tSpaceMatrix&) nogil
		tSpaceMatrix operator-(const tSpaceMatrix&) nogil
		tSpaceMatrix& operator=(const tSpaceMatrix&) nogil
		
		# methods
		## maths
		tSpaceMatrix transpose() nogil
		tSpaceMatrix exp() nogil
		## data
		double* data() nogil
		unsigned int size() nogil

cdef extern from "param/parameters.h" namespace "c0p":
	cdef cppclass tViewSpaceVector "c0p::tView<c0p::tSpaceVector>":
		# constructor
		tViewSpaceVector(double*) nogil
		# static
		@staticmethod
		unsigned int size() nogil

		# operators
		double operator[](const int) nogil
		double& operator[](const int) nogil
		
		tSpaceVector operator*(const double) nogil
		tSpaceVector operator*(const double, const tViewSpaceVector&) nogil
		tSpaceVector operator/(const double) nogil
		
		tSpaceVector operator+(const tSpaceVector&) nogil
		tSpaceVector operator-(const tSpaceVector&) nogil
		tViewSpaceVector& operator=(const tSpaceVector&) nogil
		
		tSpaceVector operator+(tViewConstSpaceVector&) nogil
		tSpaceVector operator-(tViewConstSpaceVector&) nogil
		tViewSpaceVector& operator=(tViewConstSpaceVector&) nogil

		# methods

		## maths
		double norm() nogil
		tSpaceVector normalized() nogil
		double dot(const tSpaceVector&) nogil
		double dot(tViewConstSpaceVector&) nogil

		## data
		double* data() nogil
		unsigned int size() nogil

cdef extern from "core/prop.h" namespace "c0p":
	cdef cppclass tMatrixDynamic:
		# constructor
		## proper
		tMatrixDynamic() nogil
		tMatrixDynamic(const tSpaceMatrix) nogil
		# operators
		double operator[](const int) nogil
		double& operator[](const int) nogil

		double operator()(const int, const int) nogil
		double& operator()(const int, const int) nogil
		
		tMatrixDynamic operator*(const double) nogil
		tMatrixDynamic operator*(const double, const tMatrixDynamic&) nogil
		tMatrixDynamic operator/(const double) nogil

		tMatrixDynamic operator*(const tSpaceVector&) nogil
		# tSpaceVector operator*(const tSpaceVector&) nogil

		tMatrixDynamic operator*(const tMatrixDynamic&) nogil
		tMatrixDynamic operator+(const tMatrixDynamic&) nogil
		tMatrixDynamic operator-(const tMatrixDynamic&) nogil
		tMatrixDynamic& operator=(const tMatrixDynamic&) nogil
		
		# methods
		## maths
		double norm() nogil
		tMatrixDynamic transpose() nogil
		tMatrixDynamic block(const int, const int, const int, const int) nogil
		## data
		double* data() nogil
		unsigned int size() nogil
		void resize(const int, const int) nogil

cdef extern from "core/prop.h" namespace "c0p":
	void set(tMatrixDynamic&, const int, const int, const double) nogil
	void set(tSpaceMatrix&, const int, const int, const double) nogil

	void set(tMatrixDynamic&, const char*) nogil
	void set(tSpaceMatrix&, const char*) nogil

	void print(const tMatrixDynamic&) nogil
	void print(const tSpaceMatrix&) nogil
	void print(const double&) nogil
	void print(const tSpaceVector&) nogil
	void print(const char*) nogil

# Flow

cdef extern from "param/flow/parameters.h" namespace "c0p":
	cdef cppclass Flow:

		@staticmethod
		void prepareVelocity(const double* pX, const double t) nogil
		@staticmethod
		void prepareVelocityGradients(const double* pX, const double t) nogil
	
		@staticmethod
		tSpaceVector getVelocity(const double* pX, const double t) nogil
		@staticmethod
		tSpaceMatrix getVelocityGradients(const double* pX, const double t) nogil

cdef extern from "param/parameters.h" namespace "c0p":
	unsigned int DIM

cdef extern from "param/parameters.h" namespace "c0p::EnvParameters":

	const double cGroupSize

	const double cLength
	const double cTime
	const double cVelocity

	const tSpaceVector cDomainCenter
	const tSpaceVector cDomainSize
	# const std::array<bool, DIM> cDomainIsAxisPeriodic

	const unsigned int randomSeed
