# GLOBALS--------------------------------------------------------------------------------------------------------------
## LONGLP_PROJECT_DIR, LONGLP_PROJECT_TARGET_NAME, LONGLP_COMPILE_OPTIONS, LONGLP_COMPILE_FEATURES

# CONFIG----------------------------------------------------------------------------------------------------------------
set (
    sources_
    PRIVATE
    algorithm_base.hpp
    algorithm.hpp
    otsu.cpp
    otsu.hpp
)
set (
    deps_
    LongLP::Base
)
set (
    libs_
    PRIVATE
    LongLP::Base
    OpenMP::OpenMP_CXX ${OpenCV_LIBS} MPI::MPI_CXX
)
# SETUP TARGETS---------------------------------------------------------------------------------------------------------
longlp_make_library (
    TARGET_NAME ${LONGLP_PROJECT_TARGET_NAME}_LongLP_Binarization_Algorithm
    ALIAS_NAME LongLP::Binarization::Algorithm
    LIBRARY_TYPE OBJECT
    SOURCES ${sources_}
    COMPILE_OPTIONS PRIVATE ${LONGLP_COMPILE_OPTIONS}
    COMPILE_FEATURES PRIVATE ${LONGLP_COMPILE_FEATURES}
    INCLUDE_DIRECTORIES PRIVATE ${LONGLP_PROJECT_DIR}/src
    LINK_LIBRARIES ${libs_}
    DEPENDENCIES ${deps_}
)
