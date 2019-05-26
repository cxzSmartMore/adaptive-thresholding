# PROJECT---------------------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.14)
project (
    ImageBinarization
    VERSION 0.1.0
    LANGUAGES CXX
)

# INCLUDE MODULES AND DEPENDENCIES--------------------------------------------------------------------------------------
add_subdirectory (tools/cmake)
longlp_download_conan_cmake_if_not_exist (
    ${PROJECT_SOURCE_DIR}/conan.cmake ## need to pass absolute path
)
include (conan.cmake)
conan_cmake_run (
    CONANFILE conanfile.txt
    BASIC_SETUP
    CMAKE_TARGETS
    BUILD missing
)
find_package (OpenCV REQUIRED)
find_package (OpenMP REQUIRED)
find_package (MPI REQUIRED)

# VARIABLES-------------------------------------------------------------------------------------------------------------
set (LONGLP_PROJECT_TARGET_NAME ${PROJECT_NAME})
set (LONGLP_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
longlp_desired_compile_options (LONGLP_COMPILE_OPTIONS)
longlp_desired_compile_features (LONGLP_COMPILE_FEATURES)

# SETUP TARGET----------------------------------------------------------------------------------------------------------
add_subdirectory (data)
add_subdirectory (src)
longlp_make_exec (
    TARGET_NAME ${LONGLP_PROJECT_TARGET_NAME}
    SOURCES PRIVATE src/main.cpp
    COMPILE_OPTIONS PRIVATE ${LONGLP_COMPILE_OPTIONS}
    COMPILE_FEATURES PRIVATE ${LONGLP_COMPILE_FEATURES}
    LINK_LIBRARIES PRIVATE OpenMP::OpenMP_CXX ${OpenCV_LIBS} MPI::MPI_CXX LongLP::Binarization
    INCLUDE_DIRECTORIES PRIVATE src
    DEPENDENCIES ${LONGLP_PROJECT_TARGET_NAME}_Data LongLP::Binarization
)
