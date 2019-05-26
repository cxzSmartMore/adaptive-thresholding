#include "binarization/performance/performance_calculator.hpp"
#include <omp.h>
#include "binarization/constant.hpp"

using longlp::binarization::ConfusionMatrix;
using longlp::binarization::PerformanceCalculator;
using Result = PerformanceCalculator::Result;

std::optional<Result> PerformanceCalculator::CalculatePerformance(const cv::Mat& ground_truth,
                                                                  const cv::Mat& candidate) {
  std::optional<Result> result = std::nullopt;

  if (const auto& confusion_matrix = ConfusionMatrix::Create(ground_truth, candidate);
      confusion_matrix.has_value()) {
    auto actual_result = Result{};

    actual_result.psnr      = CalculatePSNR(confusion_matrix.value());
    actual_result.nrm       = CalculateNRM(confusion_matrix.value());
    actual_result.f_measure = CalculateFMeasure(confusion_matrix.value());
    actual_result.accuracy  = CalculateAccuracy(confusion_matrix.value());

    result = actual_result;
  }

  return result;
}

float PerformanceCalculator::CalculateAccuracy(const ConfusionMatrix& matrix) {
  const auto accurate = matrix.Accurate();
  const auto total    = matrix.Total();
  return static_cast<float>(accurate) / total;
}

float PerformanceCalculator::CalculateFMeasure(const ConfusionMatrix& matrix) {
  const auto precision = static_cast<float>(matrix.true_positive) / (matrix.ClassifiedPositive());
  const auto recall    = static_cast<float>(matrix.true_positive) / (matrix.ActualPositive());
  return (2 * precision * recall) / (precision + recall);
}

float PerformanceCalculator::CalculatePSNR(const ConfusionMatrix& matrix) {
  auto psnr = 0.0f;
  // in binarization context, sum square error is equivalent to inaccurate
  if (const auto sse = matrix.Inaccurate(); sse != 0) {
    const auto mse = static_cast<float>(sse) / matrix.Total();
    psnr           = 10 * std::log10(1 / mse);
  }

  return psnr;
}

float PerformanceCalculator::CalculateNRM(const ConfusionMatrix& matrix) {
  // negative rate : false negative
  const auto false_negative_rate =
      static_cast<float>(matrix.false_negative) / (matrix.ActualPositive());
  // negative rate: false positive
  const auto false_positive_rate =
      static_cast<float>(matrix.false_positive) / (matrix.ActualNegative());

  return (false_negative_rate + false_positive_rate) / 2;
}
