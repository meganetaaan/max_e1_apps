cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(max_e1_examples VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(dynamixel_install_dir ../../DynamixelSDK-3.7.51/c++/build/linux_sbc/install)
set(dynamixel_lib_name dxl_sbc_cpp)
include_directories(${dynamixel_install_dir}/include)
link_directories(${dynamixel_install_dir}/lib)

include_directories(../max_e1_lib/include)
link_directories(../max_e1_lib/build)

add_executable(sensors_example src/sensors_example.cpp)
target_link_libraries(sensors_example max_e1 ${dynamixel_lib_name})

add_executable(actuators_example src/actuators_example.cpp)
target_link_libraries(actuators_example max_e1 ${dynamixel_lib_name})

add_executable(motions_example src/motions_example.cpp)
target_link_libraries(motions_example max_e1 ${dynamixel_lib_name})
