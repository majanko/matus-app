#===================================================================#
# This program is the confidential and proprietary product of Valeo #
# Comfort and Driving Assistance Systems. Any unauthorised use,     #
# reproduction or transfer of this program is strictly prohibited.  #
#                                                                   #
# Copyright (C) 2018 Valeo Comfort and Driving Assistance Systems.  #
# (Subject to limited distribution and restricted disclosure only.) #
#===================================================================#


# CMake Version Requirement
cmake_minimum_required(VERSION 3.3)

# Project Name 
project(matus-app)

# Project Definitions
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")


#===================================================================#
# Project Executables
#===================================================================#

# Local Includes
include_directories("${PROJECT_SOURCE_DIR}/inc")

# Check for PkgConfig package
find_package(PkgConfig REQUIRED)

# Include Diagnostic Log&Trace user library
pkg_check_modules(DLT REQUIRED automotive-dlt)
message(STATUS "DLT version:      ${DLT_VERSION}")
message(STATUS "DLT include dirs: ${DLT_INCLUDE_DIRS}")
message(STATUS "DLT link dirs:    ${DLT_LIBDIR}")
include_directories(${DLT_INCLUDE_DIRS})
link_directories(${DLT_LIBDIR})

# Include Boost library
set(Boost_USE_STATIC_LIBS    OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.63.0 REQUIRED COMPONENTS date_time)
message(STATUS "Boost version:      ${Boost_VERSION}")
message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIR}")
message(STATUS "Boost link dirs:    ${Boost_LIBRARY_DIR}")
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# Local Sources
set(am-demo-first-app_SOURCES
	src/main.cpp
        src/message.cpp
)

# Executables
add_executable(matus-app ${am-demo-first-app_SOURCES})
target_link_libraries(matus-app ${DLT_LIBRARIES} ${Boost_LIBRARIES})


#===================================================================#
# Project Libraries
#===================================================================#




#===================================================================#
# Project Unit Tests
#===================================================================#

#===================================================================#
# Project Installs
#===================================================================#

install(TARGETS matus-app RUNTIME DESTINATION bin)
