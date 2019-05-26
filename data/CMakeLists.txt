# GLOBALS---------------------------------------------------------------------------------------------------------------
## LONGLP_PROJECT_TARGET_NAME, LONGLP_PROJECT_DIR

# SETUP TARGETS---------------------------------------------------------------------------------------------------------
add_custom_target (
    ${LONGLP_PROJECT_TARGET_NAME}_Data
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ./data ${CMAKE_BINARY_DIR}/data
    VERBATIM
    WORKING_DIRECTORY ${LONGLP_PROJECT_DIR}
    USES_TERMINAL
    COMMENT "copy ${LONGLP_PROJECT_DIR}/data to ${CMAKE_BINARY_DIR}/data"
)
