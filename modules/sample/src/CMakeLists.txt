#if(WIN32)
#    add_custom_command(
#        TARGET ${MODULE_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        "${${CMAKE_PROJECT_NAME}_IMPLICITLY_LINKED_MODULES}"
#        $<TARGET_FILE_DIR:${MODULE_NAME}>
#    )
#endif()