# GLOBALS---------------------------------------------------------------------------------------------------------------
## LONGLP_PROJECT_DIR, LONGLP_PROJECT_TARGET_NAME, LONGLP_COMPILE_OPTIONS, LONGLP_COMPILE_FEATURES
## OpenCV_LIBS, OpenMP::OpenMP_CXX, MPI::MPI_CXX
# CONFIG----------------------------------------------------------------------------------------------------------------
file (
    GLOB_RECURSE IMAGE_PROCESSING_SOURCES
    FOLLOW_SYMLINKS
    CONFIGURE_DEPENDS
    LIST_DIRECTORIES false
    *.cpp *.hpp
)
set (IMAGE_PROCESSING_LIBS
     PUBLIC ${OpenCV_LIBS} OpenMP::OpenMP_CXX MPI::MPI_CXX
     PRIVATE LongLP::Base)
# SETUP TARGET----------------------------------------------------------------------------------------------------------
longlp_make_library (
    TARGET_NAME ImageProcessing
    ALIAS_NAME LongLP::ImageProcessing
    LIBRARY_TYPE STATIC
    SOURCES PRIVATE ${IMAGE_PROCESSING_SOURCES}
    COMPILE_OPTIONS PUBLIC ${LONGLP_COMPILE_OPTIONS}
    COMPILE_FEATURES PUBLIC ${LONGLP_COMPILE_FEATURES}
    INCLUDE_DIRECTORIES PRIVATE ${LONGLP_PROJECT_DIR}/src
    LINK_LIBRARIES ${IMAGE_PROCESSING_LIBS}
)

