#include "image_processing/binarization/bernsen.hpp"
#include <opencv2/imgproc.hpp>
namespace {
  using cv::Mat;
  using longlp::image_processing::Bernsen;
  using std::is_same_v;

}  // namespace

void Bernsen::ProcessImpl(Mat& input, const Parameter& param) const {
  Mat        min_filter;
  Mat        max_filter;
  const auto kernel = cv::getStructuringElement(cv::MorphShapes::MORPH_RECT,
                                                cv::Size{param.block_size, param.block_size});
  cv::erode(input, min_filter, kernel);
  cv::dilate(input, max_filter, kernel);

  input.forEach<GrayScalePixel>(
      [contrast_threshold = param.contrast_threshold, &min_filter, &max_filter, &input](
          GrayScalePixel& pixel, const int* position) {
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
