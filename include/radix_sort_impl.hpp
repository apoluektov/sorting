// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef RADIXSORTIMPL_HPP_INCLUDED_
#define RADIXSORTIMPL_HPP_INCLUDED_

#include <boost/static_assert.hpp>
#include <cstddef>
#include <vector>


namespace radix_sort_aux
{

inline
size_t mpow(size_t base, size_t power)
{
    size_t r = 1;
    for (size_t i = 0; i < power; ++i)
        r *= base;

    return r;
}

template <size_t Radix>
inline
size_t nth_digit(size_t num, size_t n)
{
    size_t m = mpow(Radix, n);

    size_t r = num % (Radix * m);
    return r / m;
}

template <>
inline
size_t nth_digit<2>(size_t num, size_t n)
{
    return (num >> n) & 1;
}

inline
size_t num_digits(size_t num, size_t radix)
{
    int n = 1;
    while ((num /= radix) != 0) {
        ++n;
    }
    return n;
}

template <size_t Radix, class RanIt, class T>
inline
void sort_nth_digit(RanIt b, RanIt e, size_t digit, std::vector<T>& tmp)
{
    // first pass: fill buckets' info
    size_t buckets[Radix] = { 0 };
    for (RanIt c = b ; c != e; ++c) {
        size_t d = nth_digit<Radix>(*c, digit);
        ++buckets[d];
    }

    size_t counters[Radix] = { 0 };
    for (size_t i = 1; i < Radix; ++i) {
        counters[i] = counters[i-1] + buckets[i-1];
    }

    // second pass: sort
    for (RanIt c = b; c != e; ++c) {
        size_t d = nth_digit<Radix>(*c, digit);
        tmp[counters[d]++] = *c;
    }
    std::copy(tmp.begin(), tmp.end(), b);
}

} // namespace radix_sort_aux


template <size_t Radix, class RanIt>
inline
void radix_sort(RanIt b, RanIt e, size_t max)
{
    BOOST_STATIC_ASSERT(Radix > 1);

    typedef typename std::iterator_traits<RanIt>::value_type T;
    std::vector<T> tmp(e - b);

    size_t const ndigits = radix_sort_aux::num_digits(max, Radix);
    for (size_t d = 0; d < ndigits; ++d)
        radix_sort_aux::sort_nth_digit<Radix>(b, e, d, tmp);
}

template <size_t Radix, class Cont>
inline
void radix_sort(Cont& v, size_t max)
{
    return radix_sort<Radix>(v.begin(), v.end(), max);
}

#endif // RADIXSORTIMPL_HPP_INCLUDED_
