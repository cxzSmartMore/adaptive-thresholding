#include "confusion_matrix.hpp"
#include "image_processing/constant.hpp"
using longlp::image_processing::ConfusionMatrix;

uint64_t ConfusionMatrix::Total() const {
  return true_positive + true_negative + false_positive + false_negative;
}

uint64_t ConfusionMatrix::Accurate() const {
  return true_positive + true_negative;
}

uint64_t ConfusionMatrix::Inaccurate() const {
  return false_positive + false_negative;
}

uint64_t ConfusionMatrix::ActualPositive() const {
  return true_positive + false_negative;
}

uint64_t ConfusionMatrix::ActualNegative() const {
  return false_positive + true_negative;
}

uint64_t ConfusionMatrix::ClassifiedPositive() const {
  return true_positive + false_positive;
}

uint64_t ConfusionMatrix::ClassifiedNegative() const {
  return true_negative + false_negative;
}

std::optional<ConfusionMatrix> ConfusionMatrix::Create(const cv::Mat& ground_truth,
                                                       const cv::Mat& candidate) {
  std::optional<ConfusionMatrix> result = std::nullopt;

  // have result
  if (ground_truth.size() == candidate.size() and
      ground_truth.channels() == candidate.channels() and ground_truth.channels() == 1) {
    ConfusionMatrix matrix{};

    // Analyze candidate and ground-truth
    for (size_t idx = 0; idx < ground_truth.total(); ++idx) {
      const auto pixel_gt        = ground_truth.data[idx];
      const auto pixel_candidate = candidate.data[idx];

      // true
      if (pixel_gt == pixel_candidate) {
        // positive
        if (pixel_candidate == GRAYSCALE_BLACK) {
          ++matrix.true_positive;
        }
        // negative
        else {
          ++matrix.true_negative;
        }
      }
      // false
      else {
        // positive
        if (pixel_candidate == GRAYSCALE_BLACK) {
          ++matrix.false_positive;
        }
        // negative
        else {
          ++matrix.false_negative;
        }
      }
    }

    result = matrix;
  }

  return result;
}
