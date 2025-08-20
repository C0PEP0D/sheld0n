
conan profile detect --force

<!-- conan install . --build=missing -->
<!-- cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -->

conan build .
