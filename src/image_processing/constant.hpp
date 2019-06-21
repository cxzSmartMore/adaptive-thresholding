#ifndef SRC_IMAGE_PROCESSING_CONSTANT_HPP
#define SRC_IMAGE_PROCESSING_CONSTANT_HPP
#pragma once
#include <cstdint>
#include <opencv2/core.hpp>
namespace longlp::image_processing {
  constexpr uint8_t GRAYSCALE_BLACK = 0;
  constexpr uint8_t GRAYSCALE_WHITE = 255;
  constexpr auto    GRAYSCALE_MIN   = GRAYSCALE_BLACK;
  constexpr auto    GRAYSCALE_MAX   = GRAYSCALE_WHITE;

  using AlgorithmTag                     = uint32_t;
  constexpr AlgorithmTag NoTag           = 0;
  constexpr AlgorithmTag Binarization    = 1;
  constexpr AlgorithmTag Skeletonization = 2;

  using GrayScalePixel = uint8_t;
}  // namespace longlp::image_processing
#endif  // SRC_IMAGE_PROCESSING_CONSTANT_HPP
