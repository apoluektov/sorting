// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef RADIXSORT_HPP_INCLUDED_
#define RADIXSORT_HPP_INCLUDED_

#include <cstddef>


// iterators versions

template <size_t Radix, class RandomAccessIterator>
void radix_sort(RandomAccessIterator first, RandomAccessIterator last,
                size_t max);

// container versions

template <size_t Radix, class Container>
void radix_sort(Container& v, size_t max);


// implementation

#include <radix_sort_impl.hpp>

#endif // MERGESORT_HPP_INCLUDED_
