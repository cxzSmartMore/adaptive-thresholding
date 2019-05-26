#ifndef SRC_BINARIZATION_ALGORITHM_OTSU_HPP
#define SRC_BINARIZATION_ALGORITHM_OTSU_HPP

#pragma once
#include "binarization/algorithm/algorithm_base.hpp"

namespace longlp::binarization {
  class Otsu final : public AlgorithmBase<Otsu> {
   private:
    friend AlgorithmBase<Otsu>;

    [[nodiscard]] cv::Mat BinarizeImpl(const cv::Mat& input) const;
    void                  BinarizeImpl(cv::Mat& img) const;

    static constexpr uint32_t HISTOGRAM_SIZE = 256;
  };
}  // namespace longlp::binarization
#endif  // SRC_BINARIZATION_ALGORITHM_OTSU_HPP
