include(${CMAKE_TOOLS_DIR}/GenerateSourceGroups.cmake)

include_directories(${cpp-futile-engine_SOURCE_DIR})

file(GLOB_RECURSE cpp-futile-engine_HEADERS "${cpp-futile-engine_SOURCE_DIR}/dapps/*.hpp")

install(FILES ${cpp-futile-engine_HEADERS} DESTINATION include)

add_executable(cpp-futile-engine main.cpp ${cpp-futile-engine_HEADERS})

target_link_libraries(cpp-futile-engine ${SDL2_LIBRARY}
                                        ${SDL2_IMAGE_LIBRARIES}
                                        ${SDL2_TTF_LIBRARIES})