cmake_minimum_required(VERSION 3.27)

project(DoubleSum)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -lm -lgmp")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -lm -lgmp")


include_directories(src)
add_executable(DoubleSum src/main.c
			 src/algorithm/naive_sum.c
			 src/algorithm/exact_sum.c
			 src/algorithm/kahan_sum.c
			 src/algorithm/ogita_oishi_sum.c
			 src/algorithm/kahan_babushka_klein_sum.c
			 src/io/io.c)

add_executable(generator src/generator/generator.c)
