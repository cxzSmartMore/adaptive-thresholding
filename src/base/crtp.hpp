#ifndef SRC_BASE_CRTP_HPP
#define SRC_BASE_CRTP_HPP

namespace longlp::base {
  template <typename T, template <typename> class CRTPType>
  class crtp {
   public:
    [[nodiscard]] T&       underlying() { return static_cast<T&>(*this); }
    [[nodiscard]] const T& underlying() const { return static_cast<const T&>(*this); }

   private:
    constexpr explicit crtp() = default;
    friend CRTPType<T>;
  };
}  // namespace longlp::base

#endif  // SRC_BASE_CRTP_HPP
