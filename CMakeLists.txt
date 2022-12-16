cmake_minimum_required(VERSION 3.0)

project(MultiDimensionalDynamicArray)

# Use cmake --log-level=debug to get debug output.
set(CMAKE_MESSAGE_LOG_LEVEL "STATUS")

add_subdirectory(MultiDimensionalDynamicArray)

add_executable(MultiDimensionalDynamicArray main.cpp)
target_link_libraries(MultiDimensionalDynamicArray MultiDimensionalDynamicArrayLib)

