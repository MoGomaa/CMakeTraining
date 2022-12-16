message("Configuring MultiDimensionalDynamicArrayLib")

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/MultiDimensionalDynamicArray.cpp")
    message(FATAL_ERROR "MultiDimensionalDynamicArray.cpp not found")
else()
    message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/src/MultiDimensionalDynamicArray.cpp found")
endif()

add_library(MultiDimensionalDynamicArrayLib ${CMAKE_CURRENT_SOURCE_DIR}/src/MultiDimensionalDynamicArray.cpp)
target_include_directories(MultiDimensionalDynamicArrayLib PUBLIC include)