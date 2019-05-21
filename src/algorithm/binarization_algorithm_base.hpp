#ifndef SRC_ALGORITHM_BINARIZATION_ALGORITHM_BASE_HPP
#define SRC_ALGORITHM_BINARIZATION_ALGORITHM_BASE_HPP
#include <opencv2/core.hpp>
#include "base/crtp.hpp"
namespace longlp::algorithm {
  template <typename Derived>
  struct BinarizationAlgorithm : longlp::base::crtp<Derived, BinarizationAlgorithm> {
    [[nodiscard]] cv::Mat Binarize(const cv::Mat& input) const {
      return this->underlying().BinarizeImpl(input);
    }

    void Binarize(cv::Mat& input) const { this->underlying().BinarizeImpl(input); }

   private:
    friend Derived;
    explicit constexpr BinarizationAlgorithm() = default;

    /*
     * Implement
     * [[nodiscard]] cv::Mat BinarizeImpl(const cv::Mat& input) const
     * void BinarizeImpl(cv::Mat& input) const
     * */
  };
}  // namespace longlp::algorithm
#endif  // SRC_ALGORITHM_BINARIZATION_ALGORITHM_BASE_HPP
