#ifndef SRC_BINARIZATION_ALGORITHM_ALGORITHM_BASE_HPP
#define SRC_BINARIZATION_ALGORITHM_ALGORITHM_BASE_HPP
#pragma once
#include <opencv2/core.hpp>
#include "base/crtp.hpp"
namespace longlp::binarization {
  template <typename Derived>
  class AlgorithmBase : public longlp::base::crtp<Derived, AlgorithmBase> {
   public:
    [[nodiscard]] cv::Mat Binarize(const cv::Mat& input) const {
      return this->underlying().BinarizeImpl(input);
    }

    void Binarize(cv::Mat& input) const { this->underlying().BinarizeImpl(input); }

   private:
    friend Derived;
    /*
     * Implement
     * [[nodiscard]] cv::Mat BinarizeImpl(const cv::Mat& input) const
     * void BinarizeImpl(cv::Mat& input) const
     * */
  };
}  // namespace longlp::binarization
#endif  // SRC_BINARIZATION_ALGORITHM_ALGORITHM_BASE_HPP
