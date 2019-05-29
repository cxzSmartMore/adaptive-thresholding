#include "performance_calculator.hpp"
#include <omp.h>
#include "image_processing/constant.hpp"

using longlp::image_processing::ConfusionMatrix;
using longlp::image_processing::PerformanceCalculator;

double PerformanceCalculator::CalculateAccuracy(const ConfusionMatrix& matrix) {
  const auto accurate = matrix.Accurate();
  const auto total    = matrix.Total();
  return static_cast<double>(accurate) / total;
}

double PerformanceCalculator::CalculateFMeasure(const ConfusionMatrix& matrix) {
  const auto precision = static_cast<double>(matrix.true_positive) / (matrix.ClassifiedPositive());
  const auto recall    = static_cast<double>(matrix.true_positive) / (matrix.ActualPositive());
  return (2 * precision * recall) / (precision + recall);
}

double PerformanceCalculator::CalculatePSNR(const ConfusionMatrix& matrix) {
  auto psnr = 0.0;
  // in binarization context, sum square error is equivalent to inaccurate
  if (const auto sse = matrix.Inaccurate(); sse != 0) {
    const auto mse = static_cast<double>(sse) / matrix.Total();
    psnr           = 10 * std::log10(1 / mse);
  }

  return psnr;
}

double PerformanceCalculator::CalculateNRM(const ConfusionMatrix& matrix) {
  // negative rate : false negative
  const auto false_negative_rate =
      static_cast<double>(matrix.false_negative) / (matrix.ActualPositive());
  // negative rate: false positive
  const auto false_positive_rate =
      static_cast<double>(matrix.false_positive) / (matrix.ActualNegative());

  return (false_negative_rate + false_positive_rate) / 2;
}
