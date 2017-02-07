cmake_minimum_required(VERSION 2.6)

project(cpp-futile-engine)

set(cpp-futile-engine_VERSION_MAJOR 0)
set(cpp-futile-engine_VERSION_MINOR 1)
set(cpp-futile-engine_VERSION_STRING ${cpp-futile-engine_VERSION_MAJOR}.${cpp-futile-engine_VERSION_MINOR})

set(CMAKE_TOOLS_DIR "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel..")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Whether to build shared or static libraries.")
set(Boost_DEBUG OFF CACHE BOOL "Show boost debugging information.")
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "Whether to use shared or static boost libraries when building.")
set(Boost_USE_STATIC_RUNTIME OFF CACHE BOOL "If enabled, searches for boost libraries linked against a static C++ standard library ('s' ABI tag). Defaults to OFF.")
set(Boost_USE_MULTITHREADED ON CACHE BOOL "Whether to link to multi-threaded boost libraries when building.")

if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
endif()

if(WIN32)
	add_definitions(-D_WIN32_WINNT=0x0501)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

enable_testing()

add_subdirectory(src/)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${cpp-futile-engine_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${cpp-futile-engine_VERSION_MINOR}")
include(CPack)