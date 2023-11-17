
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

project (${PROJECT_NAME} hellopcl CXX)

set(CMAKE_BUILD_TYPE "Release")

set(PCL_DIR "D:/devtools/pcl-1.13.1/share/pcl-1.13")
find_package(PCL REQUIRED)

if(PCL_FOUND)
    message ("pcl found")
else()
    message (FATAL_ERROR "pcl isnot found")
endif()


set(VTK_DIR "D:/devtools/VTK.9.3.0/lib/cmake/vtk-9.3")
find_package(VTK REQUIRED)

if(VTK_FOUND)
    message ("VTK found")
else()
    message (FATAL_ERROR "VTK isnot found")
endif()


add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
   ${VTK_LIBRARIES} ${PCL_LIBRARIES}
)

INCLUDE_DIRECTORIES(${PCL_INCLUDE_DIRS} ${VTK_INCLUDE_DIRS} ${PCL_LIBRARIES})

# message("---------------------------------" ${VTK_LIBRARIES})
# message("---------------------------------" ${PCL_LIBRARIES})

file( COPY milk.pcd DESTINATION ./)
