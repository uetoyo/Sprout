#ifndef SPROUT_COMPRESSED_PAIR_HPP
#define SPROUT_COMPRESSED_PAIR_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/detail/call_traits.hpp>

namespace sprout {
	namespace detail {
		template<typename T1, typename T2, bool IsSame, bool FirstEmpty, bool SecondEmpty>
		struct compressed_pair_switch;
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, false, false, false>
			: public std::integral_constant<int, 0>
		{};
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, false, true, false>
			: public std::integral_constant<int, 1>
		{};
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, false, false, true>
			: public std::integral_constant<int, 2>
		{};
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, false, true, true>
			: public std::integral_constant<int, 3>
		{};
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, true, true, true>
			: public std::integral_constant<int, 4>
		{};
		template<typename T1, typename T2>
		struct compressed_pair_switch<T1, T2, true, false, false>
			: public std::integral_constant<int, 5>
		{};

		template<typename T1, typename T2, int Version>
		class compressed_pair_impl;
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 0>
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		private:
			first_type first_;
			second_type second_;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_(x)
				, second_(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_(x)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(second_param_type y)
				: second_(y)
			{}
			first_reference first() {
				return first_;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return first_;
			}
			second_reference second() {
				return second_;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return second_;
			}
			void swap(compressed_pair_impl& other) {
				using std::swap;
				swap(first_, other.first_);
				swap(second_, other.second_);
			}
		};
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 1>
			: protected std::remove_cv<T1>::type
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		private:
			second_type second_;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_type(x)
				, second_(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_type(x)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(second_param_type y)
				: second_(y)
			{}
			first_reference first() {
				return *this;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return *this;
			}
			second_reference second() {
				return second_;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return second_;
			}
			void swap(compressed_pair_impl& other) {
				using std::swap;
				swap(second_, other.second_);
			}
		};
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 2>
			: protected std::remove_cv<T1>::type
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		private:
			first_type first_;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_(x)
				, second_type(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_(x)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(second_param_type y)
				: second_type(y)
			{}
			first_reference first() {
				return first_;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return first_;
			}
			second_reference second() {
				return *this;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return *this;
			}
			void swap(compressed_pair_impl& other) {
				using std::swap;
				swap(first_, other.first_);
			}
		};
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 3>
			: protected std::remove_cv<T1>::type
			, protected std::remove_cv<T2>::type
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_type(x)
				, second_type(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_type(x)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(second_param_type y)
				: second_type(y)
			{}
			first_reference first() {
				return *this;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return *this;
			}
			second_reference second() {
				return *this;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return *this;
			}
			void swap(compressed_pair_impl& other) {}
		};
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 4>
			: protected std::remove_cv<T1>::type
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		private:
			second_type second_;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_type(x)
				, second_(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_type(x)
				, second_(x)
			{}
			first_reference first() {
				return *this;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return *this;
			}
			second_reference second() {
				return second_;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return second_;
			}
			void swap(compressed_pair_impl& other) {}
		};
		template<typename T1, typename T2>
		class compressed_pair_impl<T1, T2, 5>
		{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
			typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
			typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
			typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
			typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
			typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
		private:
			first_type first_;
			second_type second_;
		public:
			SPROUT_CONSTEXPR compressed_pair_impl() {}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x, second_param_type y)
				: first_(x)
				, second_(y)
			{}
			SPROUT_CONSTEXPR compressed_pair_impl(first_param_type x)
				: first_(x)
				, second_(x)
			{}
			first_reference first() {
				return first_;
			}
			SPROUT_CONSTEXPR first_const_reference first() const {
				return first_;
			}
			second_reference second() {
				return second_;
			}
			SPROUT_CONSTEXPR second_const_reference second() const {
				return second_;
			}
			void swap(compressed_pair_impl& other) {
				using std::swap;
				swap(first_, other.first_);
				swap(second_, other.second_);
			}
		};
	}	// namespace detail
	
	//
	// compressed_pair
	//
	template<typename T1, typename T2>
	class compressed_pair
		: private sprout::detail::compressed_pair_impl<
			T1,
			T2,
			sprout::detail::compressed_pair_switch<
				T1,
				T2,
				std::is_same<typename std::remove_cv<T1>::type, typename std::remove_cv<T2>::type>::value,
				std::is_empty<T1>::value,
				std::is_empty<T2>::value
			>::value
		>
	{
	private:
		typedef sprout::detail::compressed_pair_impl<
			T1,
			T2,
			sprout::detail::compressed_pair_switch<
				T1,
				T2,
				std::is_same<typename std::remove_cv<T1>::type, typename std::remove_cv<T2>::type>::value,
				std::is_empty<T1>::value,
				std::is_empty<T2>::value
			>::value
		> base_type;
	public:
		typedef T1 first_type;
		typedef T2 second_type;
		typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
		typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
		typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
		typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
		typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
		typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
	public:
		SPROUT_CONSTEXPR compressed_pair()
			: base_type()
		{}
		SPROUT_CONSTEXPR compressed_pair(first_param_type x, second_param_type y)
			: base_type(x, y)
		{}
		explicit SPROUT_CONSTEXPR compressed_pair(first_param_type x)
			: base_type(x)
		{}
		explicit SPROUT_CONSTEXPR compressed_pair(second_param_type y)
			: base_type(y)
		{}
		first_reference first() {
			return base_type::first();
		}
		SPROUT_CONSTEXPR first_const_reference first() const {
			return base_type::first();
		}
		second_reference second() {
			return base_type::second();
		}
		SPROUT_CONSTEXPR second_const_reference second() const {
			return base_type::second();
		}
		void swap(compressed_pair& other) {
			base_type::swap(other);
		}
	};
	template<typename T>
	class compressed_pair<T, T>
		: private sprout::detail::compressed_pair_impl<
			T,
			T,
			sprout::detail::compressed_pair_switch<
				T,
				T,
				std::is_same<typename std::remove_cv<T>::type, typename std::remove_cv<T>::type>::value,
				std::is_empty<T>::value,
				std::is_empty<T>::value
			>::value
		>
	{
	private:
		typedef sprout::detail::compressed_pair_impl<
			T,
			T,
			sprout::detail::compressed_pair_switch<
				T,
				T,
				std::is_same<typename std::remove_cv<T>::type, typename std::remove_cv<T>::type>::value,
				std::is_empty<T>::value,
				std::is_empty<T>::value
			>::value
		> base_type;
	public:
		typedef T first_type;
		typedef T second_type;
		typedef typename sprout::detail::call_traits<first_type>::param_type first_param_type;
		typedef typename sprout::detail::call_traits<second_type>::param_type second_param_type;
		typedef typename sprout::detail::call_traits<first_type>::reference first_reference;
		typedef typename sprout::detail::call_traits<second_type>::reference second_reference;
		typedef typename sprout::detail::call_traits<first_type>::const_reference first_const_reference;
		typedef typename sprout::detail::call_traits<second_type>::const_reference second_const_reference;
	public:
		SPROUT_CONSTEXPR compressed_pair()
			: base_type()
		{}
		SPROUT_CONSTEXPR compressed_pair(first_param_type x, second_param_type y)
			: base_type(x, y)
		{}
		explicit SPROUT_CONSTEXPR compressed_pair(first_param_type x)
			: base_type(x)
		{}
		first_reference first() {
			return base_type::first();
		}
		SPROUT_CONSTEXPR first_const_reference first() const {
			return base_type::first();
		}
		second_reference second() {
			return base_type::second();
		}
		SPROUT_CONSTEXPR second_const_reference second() const {
			return base_type::second();
		}
		void swap(compressed_pair& other) {
			base_type::swap(other);
		}
	};
	template<typename T1, typename T2>
	inline void swap(sprout::compressed_pair<T1, T2>& lhs, sprout::compressed_pair<T1, T2>& rhs) {
		lhs.swap(rhs);
	}
}	// namespace sprout

#endif // #ifndef SPROUT_COMPRESSED_PAIR_HPP