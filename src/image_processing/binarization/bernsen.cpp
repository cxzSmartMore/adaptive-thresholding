#include "image_processing/binarization/bernsen.hpp"
#include <opencv2/imgproc.hpp>
#include <type_traits>
using cv::Mat;
using longlp::image_processing::Bernsen;
#include <iostream>
void Bernsen::ProcessImpl(Mat& input, const Parameter& param) const {
  /*
   * TODO:  structured bindings are never names of variables, making them never capturable
   * This fails on Clang 8, MSVC 2019
   * Works on G++ 9
   * */
  // const auto [contrast_threshold, block_size] = param;

  const auto contrast_threshold = param.contrast_threshold;
  // change to signed to make explicit conversion
  const auto block_size =
      static_cast<std::make_signed_t<decltype(param.block_size)>>(param.block_size);

  const auto kernel =
      cv::getStructuringElement(cv::MorphShapes::MORPH_RECT, cv::Size{block_size, block_size});
  Mat min_filter{};
  Mat max_filter{};
  cv::erode(input, min_filter, kernel);
  cv::dilate(input, max_filter, kernel);

  input.forEach<GrayScalePixel>([&](GrayScalePixel& pixel, const int* position) {
    const auto idx             = position[0] * input.cols + position[1];
    const auto min             = min_filter.data[idx];
    const auto max             = max_filter.data[idx];
    const auto local_contrast  = max - min;
    const auto local_threshold = (max + min) / 2;

    if (local_contrast < contrast_threshold) {
      pixel = (local_threshold >= 128) ? GRAYSCALE_WHITE : GRAYSCALE_BLACK;
    }
    else {
      pixel = (pixel >= local_threshold) ? GRAYSCALE_WHITE : GRAYSCALE_BLACK;
    }
  });
}
