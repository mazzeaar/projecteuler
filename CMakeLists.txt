cmake_minimum_required(VERSION 3.10)

project(ProjectEuler)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectory for utils
add_subdirectory(utils)

# Find all problem files
file(GLOB PROBLEM_FILES "src/problems/*.cpp")

# Add an executable for the main file
add_executable(main src/main.cpp ${PROBLEM_FILES})

# Link the utils library
target_link_libraries(main utils)

# Add custom target for running problems
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E env "N=${PROBLEM_NUMBER}" ./main ${PROBLEM_NUMBER}
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add option to specify problem number
set(PROBLEM_NUMBER "" CACHE STRING "Problem number to run")
