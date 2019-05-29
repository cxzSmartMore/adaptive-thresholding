#include <image_processing/binarization/bernsen.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "image_processing/image_processing.hpp"
namespace lpl = longlp::image_processing;
inline auto show(const std::string_view name, const cv::Mat& img) {
  cv::namedWindow(data(name), cv::WindowFlags::WINDOW_KEEPRATIO);
  cv::resizeWindow(data(name), img.size() / 4);
  cv::imshow(data(name), img);
}

template <typename T>
inline auto test(const cv::Mat& input, const typename lpl::AlgorithmBase<T>::Parameter& param) {
  const lpl::AlgorithmBase<T> algo;
  const auto                  output = algo.Process(input, param);
  show(algo.GetName(), output);
}
int main() {
  auto input = cv::imread("../data/input/2.bmp", cv::ImreadModes::IMREAD_GRAYSCALE);

  auto ground_truth = cv::imread("../data/ground-truth/2_gt.bmp");
  show("ground_truth", ground_truth);

  test<lpl::Otsu>(input, {});
  test<lpl::Bernsen>(input, {50, 3});
  cv::waitKeyEx(0);
  return 0;
}
