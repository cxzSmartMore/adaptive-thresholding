#include <opencv2/highgui.hpp>
#include "algorithm/algorithm.hpp"

int main() {
  auto input = cv::imread("/media/longlp/Data/Desktop/cpp-projects/mpi-test/data/a.png",
                          cv::ImreadModes::IMREAD_GRAYSCALE);
  longlp::algorithm::Otsu algorithm;

  cv::imshow("input", input);
  algorithm.Binarize(input);
  cv::imshow("output", input);
  cv::waitKeyEx(0);
  return 0;
}
