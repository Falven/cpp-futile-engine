#include(${CMAKE_MACRO_PATH}/GenerateLibTests.cmake)

#include_directories("${${CMAKE_PROJECT_NAME}_SOURCE_DIR}")

#generate_lib_tests(cpp-futile-engine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})