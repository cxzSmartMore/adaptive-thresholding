# GLOBALS--------------------------------------------------------------------------------------------------------------
## LONGLP_PROJECT_DIR, LONGLP_PROJECT_TARGET_NAME, LONGLP_COMPILE_OPTIONS, LONGLP_COMPILE_FEATURES

# CONFIG----------------------------------------------------------------------------------------------------------------
set (
    sources_
    PRIVATE
    performance.hpp
    confusion_matrix.cpp
    confusion_matrix.hpp
    performance_calculator.hpp
    performance_calculator.cpp
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
    TARGET_NAME ${LONGLP_PROJECT_TARGET_NAME}_LongLP_Binarization_Performance
    ALIAS_NAME LongLP::Binarization::Performance
    LIBRARY_TYPE OBJECT
    SOURCES ${sources_}
    COMPILE_OPTIONS PRIVATE ${LONGLP_COMPILE_OPTIONS}
    COMPILE_FEATURES PRIVATE ${LONGLP_COMPILE_FEATURES}
    INCLUDE_DIRECTORIES PRIVATE ${LONGLP_PROJECT_DIR}/src
    LINK_LIBRARIES ${libs_}
    DEPENDENCIES ${deps_}
)
longlp_message (${CMAKE_CURRENT_SOURCE_DIR}/src)
