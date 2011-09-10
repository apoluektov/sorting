// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HEAPSORT_HPP_INCLUDED_
#define HEAPSORT_HPP_INCLUDED_


// iterators versions

template <class RandomAccessIterator>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp);

// container versions

template <class Container>
void heap_sort(Container& v);

template <class Container, class Compare>
void heap_sort(Container& v, Compare comp);


// implementation

#include <heap_sort_impl.hpp>

#endif // HEAPSORT_HPP_INCLUDED_
