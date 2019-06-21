#ifndef SRC_IMAGE_PROCESSING_PERFORMANCE_METRIC_PERFORMANCE_CALCULATOR_HPP
#define SRC_IMAGE_PROCESSING_PERFORMANCE_METRIC_PERFORMANCE_CALCULATOR_HPP

#pragma once
#include <opencv2/core.hpp>
#include <optional>
#include "confusion_matrix.hpp"
namespace longlp::image_processing {
  /**
   * Classification Performance Calculator
   * To measure performance of binarization algorithms
   */
  struct PerformanceCalculator final {
   public:
    // calculate similar rate to ground-truth
    // Higher is better
    [[nodiscard]] static double CalculateAccuracy(const ConfusionMatrix& matrix);

    // F-measure combines precision and recall by calculating their harmonic mean
    [[nodiscard]] static double CalculateFMeasure(const ConfusionMatrix& matrix);

    // In image analysis, Peak Signal-to-Noise Ratio (PSNR) is the maximum value between the
    // power of a signal and corrupting noise. In binarization context, this ratio measures how
    // close an candidate image is to the ground-truth image
    // Higher is better
    [[nodiscard]] static double CalculatePSNR(const ConfusionMatrix& matrix);

    // The Negative Rate Metric is a numerical equivalent of the relation between misclassified
    // elements and all other elements in the class
    // Lower is better
    [[nodiscard]] static double CalculateNRM(const ConfusionMatrix& matrix);
  };

}  // namespace longlp::image_processing

#endif  // SRC_IMAGE_PROCESSING_PERFORMANCE_METRIC_PERFORMANCE_CALCULATOR_HPP
