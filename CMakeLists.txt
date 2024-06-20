cmake_minimum_required(VERSION 3.10)

project(ProjectEuler)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(utils)

file(GLOB PROBLEM_FILES "src/problems/*.cpp")

add_executable(main src/main.cpp ${PROBLEM_FILES})
target_link_libraries(main utils)

# runs a specific problem number
add_custom_target(run_specific
    COMMAND ${CMAKE_COMMAND} -E env "N=${PROBLEM_NUMBER}" ./main ${PROBLEM_NUMBER}
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# runs all problems sequentially
add_custom_target(test
    COMMAND ./main "all"
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# runs the problem with the highest number
add_custom_target(run
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add option to specify problem number
set(PROBLEM_NUMBER "" CACHE STRING "Problem number to run")

# compiler flags for debug/release
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Werror")

# print the buildtype being used
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
