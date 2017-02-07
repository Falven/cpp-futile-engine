include(${CMAKE_TOOLS_DIR}/GenerateSourceGroups.cmake)

include_directories(${cpp-futile-engine_SOURCE_DIR})

file(GLOB_RECURSE cpp-futile-engine_HEADERS "${cpp-futile-engine_SOURCE_DIR}/dapps/*.hpp")

install(FILES ${cpp-futile-engine_HEADERS} DESTINATION include)

add_library(cpp-futile-engine INTERFACE)
target_sources(cpp-futile-engine INTERFACE ${cpp-futile-engine_HEADERS})
target_link_libraries(cpp-futile-engine INTERFACE ${Boost_LIBRARIES})

add_custom_target(cpp-futile-engine-src SOURCES ${cpp-futile-engine_HEADERS})

GenerateSourceGroups(dapps)