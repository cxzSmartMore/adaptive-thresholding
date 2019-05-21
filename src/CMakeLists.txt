# CONFIG--------------------------------------------------------------------------------------------
longlp_desired_compile_options(compile_options_)
longlp_desired_compile_features(compile_features_)
find_package(OpenMP REQUIRED)
find_package(OpenCV REQUIRED)
# TARGET--------------------------------------------------------------------------------------------
add_executable(${LONGLP_TARGET_NAME})
target_link_libraries(
    ${LONGLP_TARGET_NAME}
    PRIVATE ${OpenCV_LIBS} ${OpenMP_CXX_LIBRARIES}
)
target_include_directories(
    ${LONGLP_TARGET_NAME}
    PRIVATE . ${OpenCV_INCLUDE_DIRS}
)
target_compile_features(
    ${LONGLP_TARGET_NAME}
    PRIVATE ${compile_features_}
)
target_compile_options(
    ${LONGLP_TARGET_NAME}
    PRIVATE ${compile_options_}
)
set(
    sources_
    main.cpp
    base/crtp.hpp
    algorithm/binarization_algorithm_base.hpp
    algorithm/algorithm.hpp
    algorithm/otsu.cpp
    algorithm/otsu.hpp
)
target_sources(${LONGLP_TARGET_NAME} PRIVATE ${sources_})
