#ifndef SRC_BINARIZATION_CONSTANT_HPP
#define SRC_BINARIZATION_CONSTANT_HPP
#pragma once
#include <cstdint>
namespace longlp::binarization {
  constexpr uint8_t GRAYSCALE_BLACK    = 0;
  constexpr uint8_t GRAYSCALE_WHITE    = 255;
  constexpr uint8_t GRAYSCALE_MAX_DIFF = GRAYSCALE_WHITE - GRAYSCALE_BLACK;
}  // namespace longlp::binarization
#endif  // SRC_BINARIZATION_CONSTANT_HPP
