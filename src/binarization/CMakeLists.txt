# GLOBALS--------------------------------------------------------------------------------------------------------------
## LONGLP_PROJECT_DIR, LONGLP_PROJECT_TARGET_NAME, LONGLP_COMPILE_OPTIONS, LONGLP_COMPILE_FEATURES

# CONFIG----------------------------------------------------------------------------------------------------------------
set (
    sources_
    PRIVATE
    constant.hpp
    binarization.hpp
    $<TARGET_OBJECTS:LongLP::Binarization::Algorithm>
    $<TARGET_OBJECTS:LongLP::Binarization::Performance>
)
set (
    deps_
    LongLP::Base
    LongLP::Binarization::Algorithm
    LongLP::Binarization::Performance
)
set (
    libs_
    PRIVATE
    LongLP::Base
    OpenMP::OpenMP_CXX ${OpenCV_LIBS} MPI::MPI_CXX
)
# SETUP TARGETS---------------------------------------------------------------------------------------------------------
add_subdirectory (algorithm)
add_subdirectory (performance)
longlp_make_library (
    TARGET_NAME ${LONGLP_PROJECT_TARGET_NAME}_LongLP_Binarization
    ALIAS_NAME LongLP::Binarization
    LIBRARY_TYPE STATIC
    SOURCES ${sources_}
    COMPILE_OPTIONS PRIVATE ${LONGLP_COMPILE_OPTIONS}
    COMPILE_FEATURES PRIVATE ${LONGLP_COMPILE_FEATURES}
    INCLUDE_DIRECTORIES PRIVATE ${LONGLP_PROJECT_DIR}/src
    LINK_LIBRARIES ${libs_}
    DEPENDENCIES ${deps_}
)
