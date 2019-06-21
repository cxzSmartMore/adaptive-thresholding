
#include <array>
#include <image_processing/binarization/bernsen.hpp>
#include <memory>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>
#include "image_processing/image_processing.hpp"
namespace {
  namespace lpl = longlp::image_processing;
  using cv::Mat;
  using std::data;
  using std::size;
  using std::string;
  using std::vector;

  auto show(const std::string_view name, const cv::Mat& img) {
    cv::namedWindow(data(name), cv::WindowFlags::WINDOW_NORMAL);
    cv::resizeWindow(data(name), img.size() / 4);
    cv::imshow(data(name), img);
  }

}  // namespace
int main() {
  return 0;
}
