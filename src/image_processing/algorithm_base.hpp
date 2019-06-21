#ifndef SRC_IMAGE_PROCESSING_ALGORITHM_BASE_HPP
#define SRC_IMAGE_PROCESSING_ALGORITHM_BASE_HPP
#pragma once
#include <opencv2/core.hpp>
#include <string_view>
#include "base/crtp.hpp"
#include "image_processing/constant.hpp"
namespace longlp::image_processing {

  template <typename Derived>
  class AlgorithmBase : public longlp::base::crtp<Derived, AlgorithmBase> {
   public:
    struct Parameter;

    [[nodiscard]] cv::Mat Process(const cv::Mat&                           input,
                                  const AlgorithmBase<Derived>::Parameter& param) const {
      cv::Mat result_image;
      input.copyTo(result_image);
      this->underlying().ProcessImpl(result_image, param);
      return result_image;
    }

    void Process(cv::Mat& input, const AlgorithmBase<Derived>::Parameter& param) const {
      this->underlying().ProcessImpl(input, param);
    }

    [[nodiscard]] constexpr AlgorithmTag GetTag() const { return this->underlying().GetTagImpl(); }

    [[nodiscard]] constexpr std::string_view GetName() const {
      return this->underlying().GetNameImpl();
    }

   private:
    friend Derived;
    /*
     * Implement
     * void ProcessImpl(cv::Mat& input,
     *                  const AlgorithmBase<Derived>::Parameter& param) const
     * [[nodiscard]] AlgorithmTag GetTagImpl()
     * [[nodiscard]] constexpr std::string_view GetNameImpl()
     * */
  };
}  // namespace longlp::image_processing
#endif  // SRC_IMAGE_PROCESSING_ALGORITHM_BASE_HPP
