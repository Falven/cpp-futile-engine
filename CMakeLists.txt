cmake_minimum_required(VERSION 2.6)

project(cpp-futile-engine)

set(cpp-futile-engine_VERSION_MAJOR 0)
set(cpp-futile-engine_VERSION_MINOR 1)
set(cpp-futile-engine_VERSION_STRING ${cpp-futile-engine_VERSION_MAJOR}.${cpp-futile-engine_VERSION_MINOR})

set(CMAKE_TOOLS_DIR "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_TOOLS_DIR}/sdl2")
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel..")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Whether to build shared or static libraries.")

if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
endif()

if(WIN32)
	add_definitions(-D_WIN32_WINNT=0x0501)
	set(SDL2_PATH "C:\\Program Files\\SDL2-2.0.5")
	set(SDL2_IMAGE_PATH "C:\\Program Files\\SDL2_image-2.0.1")
	set(SDL2_TTF_PATH "C:\\Program Files\\SDL2_ttf-2.0.14")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(SYSTEM
					${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
endif()

enable_testing()

add_subdirectory(src/)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${cpp-futile-engine_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${cpp-futile-engine_VERSION_MINOR}")
include(CPack)