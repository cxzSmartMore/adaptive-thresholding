#ifndef SRC_IMAGE_PROCESSING_BINARIZATION_OTSU_HPP
#define SRC_IMAGE_PROCESSING_BINARIZATION_OTSU_HPP

#pragma once
#include "image_processing/algorithm_base.hpp"

namespace longlp::image_processing {
  class Otsu;

  template <>
  struct AlgorithmBase<Otsu>::Parameter {};

  class Otsu final : public AlgorithmBase<Otsu> {
   private:
    friend AlgorithmBase<Otsu>;

    void                                 ProcessImpl(cv::Mat& input, const Parameter& param) const;
    [[nodiscard]] constexpr AlgorithmTag GetTagImpl() const { return Binarization; }
    [[nodiscard]] constexpr std::string_view GetNameImpl() const { return "Otsu"; }
    static constexpr auto                    HISTOGRAM_SIZE = 256U;
  };
}  // namespace longlp::image_processing

#endif  // SRC_IMAGE_PROCESSING_BINARIZATION_OTSU_HPP
