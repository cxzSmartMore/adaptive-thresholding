#include "binarization/algorithm/otsu.hpp"
#include <algorithm>
#include <array>
#include "binarization/constant.hpp"

using longlp::binarization::Otsu;
using std::array;

cv::Mat Otsu::BinarizeImpl(const cv::Mat& input) const {
  auto result_image = input.clone();
  BinarizeImpl(result_image);
  return result_image;
}

void Otsu::BinarizeImpl(cv::Mat& input) const {
  array<uint64_t, HISTOGRAM_SIZE> histogram{};  // initialize to 0

  for (uint64_t idx = 0; idx < input.total(); ++idx) {
    ++histogram[input.data[idx]];
  }

  float total_sum = 0.0F;
  for (uint64_t idx = 0UL; idx < HISTOGRAM_SIZE; ++idx) {
    total_sum += static_cast<float>(idx * histogram[idx]);
  }

  array    sum                        = {0.0F, total_sum};
  array    weight                     = {uint64_t{0}, input.total()};
  array    mean                       = {0.0F, 0.0F};
  float    max_between_class_variance = 0.0F;
  uint64_t threshold                  = 0;

  for (uint64_t idx = 0; idx < HISTOGRAM_SIZE; ++idx) {
    weight[0] += histogram[idx];
    if (weight[0] == 0) {
      continue;
    }

    weight[1] = input.total() - weight[0];
    if (weight[1] == 0) {
      break;
    }

    sum[0] += static_cast<float>(idx * histogram[idx]);
    sum[1]  = total_sum - sum[0];
    mean[0] = sum[0] / weight[0];
    mean[1] = sum[1] / weight[1];
    if (const auto between_class_variance = static_cast<float>(weight[0]) *
                                            static_cast<float>(weight[1]) * (mean[0] - mean[1]) *
                                            (mean[0] - mean[1]);

        between_class_variance > max_between_class_variance) {
      max_between_class_variance = between_class_variance;
      threshold                  = idx;
    }
  }

  for (auto idx = 0UL; idx < input.total(); ++idx) {
    input.data[idx] = input.data[idx] <= threshold ? GRAYSCALE_BLACK : GRAYSCALE_WHITE;
  }
}
