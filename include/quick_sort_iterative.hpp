// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QUICKSORTITERATIVE_HPP_INCLUDED_
#define QUICKSORTITERATIVE_HPP_INCLUDED_


// iterators versions

template <class RandomAccessIterator>
void quick_sort_iterative(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void quick_sort_iterative(RandomAccessIterator first, RandomAccessIterator last,
                          Compare comp);

// container versions

template <class Container>
void quick_sort_iterative(Container& v);

template <class Container, class Compare>
void quick_sort_iterative(Container& v, Compare comp);


// implementation

#include <quick_sort_iterative_impl.hpp>

#endif // QUICKSORTITERATIVE_HPP_INCLUDED_
