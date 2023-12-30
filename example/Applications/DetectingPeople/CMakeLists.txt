
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(ground_based_rgbd_people_detector)

set(BOOST_ROOT D:/devtools/boost.mingw64.1.82.0)
set(VTK_DIR D:/devtools/VTK.9.3.0/lib/cmake/vtk-9.3)

if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    set(PCL_DIR D:/devtools/pcl.1.13.1/share/pcl-1.13)
else()
    set(PCL_DIR D:/devtools/pcl.1.13.1/debug/share/pcl-1.13)
endif()

find_package(Boost 1.78 REQUIRED COMPONENTS program_options thread)
find_package(PCL 1.7 REQUIRED)
find_package(VTK REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LZ4 REQUIRED liblz4)
include_directories(${LZ4_INCLUDE_DIRS})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (ground_based_rgbd_people_detector MACOSX_BUNDLE main.cpp)
target_link_libraries (ground_based_rgbd_people_detector ${PCL_LIBRARIES})

file(COPY ./config/trainedLinearSVMForPeopleDetectionWithHOG.yaml DESTINATION ./)

