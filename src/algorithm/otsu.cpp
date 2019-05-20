#include "algorithm/otsu.hpp"
#include <omp.h>
#include <algorithm>
#include <array>

using std::array;

namespace longlp::algorithm {
  cv::Mat Otsu::BinarizeImpl(const cv::Mat& input) const {
    array<uint8_t, HISTOGRAM_SIZE> histogram{};  // initialize to 0

    for (auto idx = 0UL; idx < input.total(); ++idx) {
      ++histogram[input.data[idx]];
    }

    auto sum = 0UL;
    for (auto idx = 0UL; idx < size(histogram); ++idx) {
      sum += histogram[idx];
    }
  }
  void Otsu::BinarizeImpl(cv::Mat& input) const {}
}  // namespace longlp::algorithm
