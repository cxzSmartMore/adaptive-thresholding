#include "image_processing/binarization/otsu.hpp"
#include <array>
#include <indexed_view/indexed_view.hpp>
#include <opencv2/imgproc.hpp>

using longlp::image_processing::AlgorithmTag;
using longlp::image_processing::Otsu;
using std::array;

void Otsu::ProcessImpl(cv::Mat& input, [[maybe_unused]] const Parameter& param) const {
  static constexpr auto          epsilon = 1.0E-10;
  array<int32_t, HISTOGRAM_SIZE> histogram{};  // initialize to 0

  for (auto idx = 0U; idx < input.total(); ++idx) {
    ++histogram[input.data[idx]];
  }

  auto histogram_view = jss::indexed_view(histogram);

  auto total_sum = 0.0;
  for (const auto [index, value] : histogram_view) {
    total_sum += static_cast<double>(index) * value;
  }

  array sum                        = {0.0, total_sum};
  array weight                     = {0.0, static_cast<double>(input.total())};
  array mean                       = {0.0, 0.0};
  auto  max_between_class_variance = 0.0;
  auto  threshold                  = 0.0;

  for (const auto [index, value] : histogram_view) {
    weight[0] += static_cast<double>(value);
    if (weight[0] <= epsilon) {
      continue;
    }

    weight[1] = static_cast<double>(input.total() - weight[0]);
    if (weight[1] <= epsilon) {
      break;
    }

    sum[0] += static_cast<double>(index) * value;
    sum[1]  = total_sum - sum[0];
    mean[0] = sum[0] / weight[0];
    mean[1] = sum[1] / weight[1];
    if (const auto between_class_variance =
            weight[0] * weight[1] * (mean[0] - mean[1]) * (mean[0] - mean[1]);

        between_class_variance > max_between_class_variance) {
      max_between_class_variance = between_class_variance;
      threshold                  = index;
    }
  }
  constexpr auto type = cv::ThresholdTypes::THRESH_BINARY;
  cv::threshold(input, input, threshold, GRAYSCALE_MAX, type);
}
