from conan import ConanFile
from conan.tools.cmake import cmake_layout
from conan.tools.cmake import CMake

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("onetbb/2022.2.0")
        self.requires("gcc/12.2.0")
        self.requires("ffmpeg/7.1.1")

    def build_requirements(self):
        self.tool_requires("cmake/4.1.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
