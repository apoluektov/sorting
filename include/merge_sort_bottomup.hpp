// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef MERGESORTBOTTOMUP_HPP_INCLUDED_
#define MERGESORTBOTTOMUP_HPP_INCLUDED_


// iterators versions

template <class RandomAccessIterator>
void merge_sort_bottomup(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void merge_sort_bottomup(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp);

// container versions

template <class Container>
void merge_sort_bottomup(Container& v);

template <class Container, class Compare>
void merge_sort_bottomup(Container& v, Compare comp);


// implementation

#include <merge_sort_bottomup_impl.hpp>

#endif // MERGESORTBOTTOMUP_HPP_INCLUDED_
