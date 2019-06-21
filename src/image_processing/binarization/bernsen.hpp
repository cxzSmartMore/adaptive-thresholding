#ifndef SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP
#define SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP

#include <variant>
#include "image_processing/algorithm_base.hpp"

namespace longlp::image_processing {
  class Bernsen;

  // TODO: Need to disable struct padding related warnings
  template <>
  struct AlgorithmBase<Bernsen>::Parameter {
    uint8_t contrast_threshold;  // enforce value must be 0 - 255
    int32_t block_size;
  };

  class Bernsen final : public AlgorithmBase<Bernsen> {
   public:
    using Parameter = AlgorithmBase<Bernsen>::Parameter;

   private:
    friend AlgorithmBase<Bernsen>;

    void ProcessImpl(cv::Mat& input, const Parameter& param) const;

    [[nodiscard]] constexpr AlgorithmTag GetTagImpl() const { return Binarization; }

    [[nodiscard]] constexpr std::string_view GetNameImpl() const { return "Bernsen"; }
  };

}  // namespace longlp::image_processing

#endif  // SRC_IMAGE_PROCESSING_BINARIZATION_BERNSEN_HPP
