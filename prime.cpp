#include <iostream>

// is Prime
template <std::size_t n, std::size_t i = n - 1>
struct is_prime {
	static const bool res = (n % i == 0) ? false : is_prime<n, i - 1>::res;
};
template <std::size_t n>
struct is_prime<n, 2> {
	static const bool res = (n == 2) ? true : n % 2;
};
template <>
struct is_prime<1> {
	static const bool res = false;
};
template <>
struct is_prime<0> {
	static const bool res = false;
};

// Next Prime
template <std::size_t N, bool flag = false>
struct next_prime {
    static const std::size_t res = next_prime<N + 1, is_prime<N + 1>::res>::res;
};
template <std::size_t N>
struct next_prime<N, true> {
    static const std::size_t res = N;
};

// ith prime
template <std::size_t N, std::size_t i>
struct ith_prime {
    static const std::size_t res = ith_prime<next_prime<N>::res, i -1>::res;
};
template <std::size_t N>
struct ith_prime<N, 0> {
    static const std::size_t res = N;
};
