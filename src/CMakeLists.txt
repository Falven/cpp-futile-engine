include("${CMAKE_MACRO_PATH}/GenerateSourceGroups.cmake")

include_directories("${${CMAKE_PROJECT_NAME}_SOURCE_DIR}")

set(${CMAKE_PROJECT_NAME}_INCLUDES "${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}")
file(
    GLOB_RECURSE
    ${CMAKE_PROJECT_NAME}_HEADERS
    "${${CMAKE_PROJECT_NAME}_INCLUDES}/*.hpp" "${${CMAKE_PROJECT_NAME}_INCLUDES}/*.h"
)

install(FILES ${${CMAKE_PROJECT_NAME}_HEADERS} DESTINATION "include/${CMAKE_PROJECT_NAME}")

add_executable(cpp-futile-engine "main.cpp" "${${CMAKE_PROJECT_NAME}_HEADERS}")

target_link_libraries(cpp-futile-engine ${SDL2_LIBRARY}
                                        ${SDL2_IMAGE_LIBRARIES}
                                        ${SDL2_TTF_LIBRARIES})

if(WIN32)
    file(
        GLOB_RECURSE
        ${CMAKE_PROJECT_NAME}_EXTERNAL_LIBS
        "${${CMAKE_PROJECT_NAME}_INCLUDES}/*.hpp" "${${CMAKE_PROJECT_NAME}_INCLUDES}/*.h"
    )
    add_custom_command(
        TARGET cpp-futile-engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/libs/SDL2.dll"
        $<TARGET_FILE_DIR:cpp-futile-engine>
    )
endif()

set_property(TARGET cpp-futile-engine PROPERTY FOLDER "bin")

install(TARGETS cpp-futile-engine RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

GenerateSourceGroups(dapps)