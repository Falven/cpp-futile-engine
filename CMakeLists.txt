cmake_minimum_required(VERSION 2.6)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_VERBOSE_MAKEFILE true)
endif()

project(cpp-futile-engine)

set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR "0")
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR "0")
set(${CMAKE_PROJECT_NAME}_VERSION_PATCH "1")
set(${CMAKE_PROJECT_NAME}_VERSION_STRING "${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}.${${CMAKE_PROJECT_NAME}_VERSION_MINOR}.${${CMAKE_PROJECT_NAME}_VERSION_PATCH}")

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Whether to build shared or static libraries.")
set(CMAKE_MACRO_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/macros" CACHE STRING "Directory containing reusable CMake macros.")
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel..")

include("${CMAKE_MACRO_PATH}/ListSubDirectories.cmake")
list_sub_directories(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

if(WIN32)
	add_definitions(-D_WIN32_WINNT=0x0501)
endif()

if(UNIX)
	list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -stdlib=libc++")
endif()

set(Boost_USE_STATIC_LIBS ON CACHE BOOL "Whether to use shared or static boost libraries when building.")
set(Boost_USE_MULTITHREADED ON CACHE BOOL "Whether to link to multi-threaded boost libraries when building.")
find_package(Boost 1.63.0 REQUIRED iostreams)

if(WIN32)
	set(SDL2_PATH "C:\\Program Files\\SDL2-2.0.5")
	set(SDL2_IMAGE_PATH "C:\\Program Files\\SDL2_image-2.0.1")
	set(SDL2_TTF_PATH "C:\\Program Files\\SDL2_ttf-2.0.14")
endif()
list(APPEND CMAKE_PREFIX_PATH "${SDL2_PATH}" "${SDL2_IMAGE_PATH}" "${SDL2_TTF_PATH}")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(${CMAKE_PROJECT_NAME}_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}" CACHE STRING "Directory containing this project's headers.")
file(GLOB_RECURSE ${CMAKE_PROJECT_NAME}_HEADERS "${${CMAKE_PROJECT_NAME}_INCLUDE_DIRS}/*.h" "${${CMAKE_PROJECT_NAME}_INCLUDE_DIRS}/*.hpp" "${${CMAKE_PROJECT_NAME}_INCLUDE_DIRS}/*.hxx" "${${CMAKE_PROJECT_NAME}_INCLUDE_DIRS}/*.hh" "${${CMAKE_PROJECT_NAME}_INCLUDE_DIRS}/*.h++")
add_library(${CMAKE_PROJECT_NAME} INTERFACE)
target_sources(${CMAKE_PROJECT_NAME} INTERFACE "${${CMAKE_PROJECT_NAME}_HEADERS}")
target_include_directories(${CMAKE_PROJECT_NAME} SYSTEM INTERFACE "${Boost_INCLUDE_DIRS}")
target_link_libraries(${CMAKE_PROJECT_NAME} INTERFACE Boost::iostreams)
install(FILES ${${CMAKE_PROJECT_NAME}_HEADERS} DESTINATION "include/${CMAKE_PROJECT_NAME}")

if(WIN32)
	set(${CMAKE_PROJECT_NAME}_IMPLICITLY_LINKED_MODULES_DIR "${PROJECT_SOURCE_DIR}/lib" CACHE STRING "Directory containing dynamic libraries to be copied to output for runtime implicit linking.")
	file(GLOB ${CMAKE_PROJECT_NAME}_IMPLICITLY_LINKED_MODULES "${${CMAKE_PROJECT_NAME}_IMPLICITLY_LINKED_MODULES_DIR}/*.dll")
endif()

file(GLOB PROJECT_MODULES_DIR RELATIVE "${PROJECT_SOURCE_DIR}" "modules/**/src" "modules/**/test")
foreach(module ${PROJECT_MODULES_DIR})
  add_subdirectory(${module})
endforeach()

enable_testing()

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${${CMAKE_PROJECT_NAME}_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${${CMAKE_PROJECT_NAME}_VERSION_MINOR}")
include(CPack)