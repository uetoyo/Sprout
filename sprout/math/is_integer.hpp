#ifndef SPROUT_MATH_IS_INTEGER_HPP
#define SPROUT_MATH_IS_INTEGER_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/type_traits/enabler_if.hpp>
#include <sprout/math/isfinite.hpp>
#include <sprout/math/trunc.hpp>

namespace sprout {
	namespace math {
		namespace detail {
			template<typename T>
			inline SPROUT_CONSTEXPR bool
			is_integer_unchecked(T x) {
				return x == sprout::math::trunc(x);
			}

			template<
				typename FloatType,
				typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR bool
			is_integer(FloatType x) {
				return sprout::math::isfinite(x)
					&& sprout::math::detail::is_integer_unchecked(x)
					;
			}
		}	// namespace detail

		using sprout::math::detail::is_integer;
	}	// namespace math

	using sprout::math::is_integer;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_IS_INTEGER_HPP
