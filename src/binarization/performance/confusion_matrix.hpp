#ifndef SRC_BINARIZATION_PERFORMANCE_CONFUSION_MATRIX_HPP
#define SRC_BINARIZATION_PERFORMANCE_CONFUSION_MATRIX_HPP

#pragma once
#include <cstdint>
#include <opencv2/core.hpp>
#include <optional>

namespace longlp::binarization {
  struct ConfusionMatrix {
    // Create confusion matrix for ground_truth and candidate binary images
    // WARN: make sure input is grayscale image
    static std::optional<ConfusionMatrix> Create(const cv::Mat& ground_truth,
                                                 const cv::Mat& candidate);

    // in binarization context, @true_positive refers to number of pixels with:
    // ground-truth[i] = candidate[i] = black
    uint64_t true_positive = 0;

    // in binarization context, @false_positive refers to number of pixels with:
    // ground-truth[i] = black and candidate[i] = white
    uint64_t false_positive = 0;

    // in binarization context, @true_negative refers to number of pixels with:
    // ground-truth[i] = candidate[i] = white
    uint64_t true_negative = 0;

    // in binarization context, @false_negative refers to number of pixels with:
    // ground-truth[i] = white and candidate[i] = black
    uint64_t false_negative = 0;

    // total number of pixels
    uint64_t Total() const;

    // number of pixels: ground-truth[i] = candidate[i]
    uint64_t Accurate() const;

    // number of pixels: ground-truth[i] != candidate[i]
    uint64_t Inaccurate() const;

    // number of actual positive pixels: ground-truth[i] = black
    uint64_t ActualPositive() const;

    // number of actual negative pixels: ground-truth[i] = white
    uint64_t ActualNegative() const;

    // number of classified as positive pixels: candidate[i] = black
    uint64_t ClassifiedPositive() const;

    // number of classified as negative pixels: candidate[i] = white
    uint64_t ClassifiedNegative() const;
  };
}  // namespace longlp::binarization

#endif  // SRC_BINARIZATION_PERFORMANCE_CONFUSION_MATRIX_HPP
