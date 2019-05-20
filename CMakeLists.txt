# PROJECT-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14)
project(adaptive-thesholding
    VERSION 0.1.0
    LANGUAGES CXX)


# INCLUDE MODULES AND DEPENDENCIES------------------------------------------------------------------
add_subdirectory(tools/cmake)
longlp_download_conan_cmake_if_not_exist(
    ${PROJECT_SOURCE_DIR}/conan.cmake ## need to pass absolute path
)
include(conan.cmake)
conan_cmake_run(
    CONANFILE conanfile.txt
    BASIC_SETUP
    CMAKE_TARGETS
    BUILD missing)

# CONFIG--------------------------------------------------------------------------------------------
set(CONAN_SYSTEM_INCLUDES ON)
set(LONGLP_TARGET_NAME ${PROJECT_NAME})

# TARGETS-------------------------------------------------------------------------------------------
add_subdirectory(src)
