#ifndef SPROUT_ALGORITHM_FIT_PARTIAL_SORT_HPP
#define SPROUT_ALGORITHM_FIT_PARTIAL_SORT_HPP

#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/algorithm/fixed/partial_sort.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array.hpp>
#include HDR_ITERATOR_SSCRISK_CEL_OR_SPROUT_DETAIL

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename Container, typename Compare>
			SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type partial_sort_impl(
				Container const& cont,
				typename sprout::fixed_container_traits<Container>::const_iterator middle,
				Compare comp,
				typename sprout::fixed_container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_fixed(sprout::fixed::partial_sort(cont, middle, comp)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT_DETAIL::distance(sprout::begin(cont), middle)
					);
			}
		}	// namespace detail
		//
		// partial_sort
		//
		template<typename Container, typename Compare>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type partial_sort(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::const_iterator middle,
			Compare comp
			)
		{
			return sprout::fit::detail::partial_sort_impl(cont, middle, comp, sprout::fixed_begin_offset(cont));
		}

		namespace detail {
			template<typename Container>
			SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type partial_sort_impl(
				Container const& cont,
				typename sprout::fixed_container_traits<Container>::const_iterator middle,
				typename sprout::fixed_container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_fixed(sprout::fixed::partial_sort(cont, middle)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT_DETAIL::distance(sprout::begin(cont), middle)
					);
			}
		}	// namespace detail
		//
		// partial_sort
		//
		template<typename Container>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type partial_sort(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::const_iterator middle
			)
		{
			return sprout::fit::detail::partial_sort_impl(cont, middle, sprout::fixed_begin_offset(cont));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_FIT_PARTIAL_SORT_HPP