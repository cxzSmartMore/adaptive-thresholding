 # GLOBALS--------------------------------------------------------------------------------------------------------------
 ## LONGLP_PROJECT_DIR, LONGLP_PROJECT_TARGET_NAME, LONGLP_COMPILE_OPTIONS, LONGLP_COMPILE_FEATURES

 # CONFIG---------------------------------------------------------------------------------------------------------------

 # SETUP TARGETS--------------------------------------------------------------------------------------------------------
 longlp_make_library (
     TARGET_NAME ${LONGLP_PROJECT_TARGET_NAME}_LongLP_Base
     ALIAS_NAME LongLP::Base
     LIBRARY_TYPE INTERFACE
     SOURCES INTERFACE crtp.hpp make_array.hpp
     COMPILE_OPTIONS INTERFACE ${LONGLP_COMPILE_OPTIONS}
     COMPILE_FEATURES INTERFACE ${LONGLP_COMPILE_FEATURES}
     INCLUDE_DIRECTORIES INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/base
 )
