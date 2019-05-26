#ifndef SRC_BINARIZATION_PERFORMANCE_PERFORMANCE_CALCULATOR_HPP
#define SRC_BINARIZATION_PERFORMANCE_PERFORMANCE_CALCULATOR_HPP

#pragma once
#include <opencv2/core.hpp>
#include <optional>
#include "binarization/performance/confusion_matrix.hpp"
namespace longlp::binarization {
  /**
   * Classification Performance Calculator
   * To measure performance of binarization algorithms
   */
  class PerformanceCalculator final {
   public:
    struct Result {
      float accuracy;
      float f_measure;
      float psnr;
      float nrm;
    };

    [[nodiscard]] static std::optional<Result> CalculatePerformance(const cv::Mat& ground_truth,
                                                                    const cv::Mat& candidate);

    // calculate similar rate to ground-truth
    // Higher is better
    [[nodiscard]] static float CalculateAccuracy(const ConfusionMatrix& matrix);

    // F-measure combines precision and recall by calculating their harmonic mean
    [[nodiscard]] static float CalculateFMeasure(const ConfusionMatrix& matrix);

    // In image analysis, Peak Signal-to-Noise Ratio (PSNR) is the maximum value between the
    // power of a signal and corrupting noise. In binarization context, this ratio measures how
    // close an candidate image is to the ground-truth image
    // Higher is better
    [[nodiscard]] static float CalculatePSNR(const ConfusionMatrix& matrix);

    // The Negative Rate Metric is a numerical equivalent of the relation between misclassified
    // elements and all other elements in the class
    // Lower is better
    [[nodiscard]] static float CalculateNRM(const ConfusionMatrix& matrix);
  };

}  // namespace longlp::binarization

#endif  // SRC_BINARIZATION_PERFORMANCE_PERFORMANCE_CALCULATOR_HPP
