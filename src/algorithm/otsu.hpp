#ifndef SRC_ALGORITHM_OTSU_HPP
#define SRC_ALGORITHM_OTSU_HPP
#include "algorithm/binarization_algorithm_base.hpp"

namespace longlp::algorithm {
  class Otsu final : public BinarizationAlgorithm<Otsu> {
   private:
    [[nodiscard]] cv::Mat BinarizeImpl(const cv::Mat& input) const;
    void                  BinarizeImpl(cv::Mat& img) const;

    static constexpr size_t HISTOGRAM_SIZE = 256U;
  };
}  // namespace longlp::algorithm
#endif  // SRC_ALGORITHM_OTSU_HPP
