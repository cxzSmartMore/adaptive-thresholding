#ifndef SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP
#define SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP

// Need to disable struct padding related warnings on struct AlgorithmBase<Bernsen>::Parameter
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wpadded"
#  pragma clang diagnostic push
#elif defined(__GNUC__) || defined(__GNUG__)
#  pragma GCC diagnostic ignored "-Wpadded"
#  pragma GCC diagnostic push
#elif defined(_MSC_VER)
// TODO: find "-Wpadded" equivalent in msvc
#endif

#pragma once
#include "image_processing/algorithm_base.hpp"
namespace longlp::image_processing {
  class Bernsen;

  template <>
  struct AlgorithmBase<Bernsen>::Parameter {
    uint8_t  contrast_threshold = 25;  // enforce value must be 0 - 255
    uint32_t block_size         = 3;
  };

  class Bernsen final : public AlgorithmBase<Bernsen> {
   private:
    friend AlgorithmBase<Bernsen>;

    void                                 ProcessImpl(cv::Mat& input, const Parameter& param) const;
    [[nodiscard]] constexpr AlgorithmTag GetTagImpl() const { return Binarization; }
    [[nodiscard]] constexpr std::string_view GetNameImpl() const { return "Bernsen"; }
  };
}  // namespace longlp::image_processing

#if defined(__clang__)
#  pragma clang diagnostic pop
#elif defined(__GNUC__) || defined(__GNUG__)
#  pragma GCC diagnostic pop
#elif defined(_MSC_VER)

#endif

#endif  // SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP
