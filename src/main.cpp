#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "binarization/binarization.hpp"
int main() {
  auto input = cv::imread("../data/input/2.bmp", cv::ImreadModes::IMREAD_GRAYSCALE);
  cv::namedWindow("input", cv::WindowFlags::WINDOW_NORMAL);
  cv::resizeWindow("input", 600, 600);
  cv::imshow("input", input);

  auto ground_truth = cv::imread("../data/ground-truth/2_gt.bmp");
  cv::namedWindow("ground_truth", cv::WindowFlags::WINDOW_NORMAL);
  cv::resizeWindow("ground_truth", 600, 600);
  cv::imshow("ground_truth", ground_truth);

  longlp::binarization::Otsu algorithm;
  algorithm.Binarize(input);
  cv::namedWindow("otsu", cv::WindowFlags::WINDOW_NORMAL);
  cv::resizeWindow("otsu", 600, 600);
  cv::imshow("otsu", input);

  cv::waitKeyEx(0);
  return 0;
}
