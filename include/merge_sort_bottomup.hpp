// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef MERGESORTBOTTOMUP_HPP_INCLUDED_
#define MERGESORTBOTTOMUP_HPP_INCLUDED_


// iterators versions

template <class RanIt, class Cmp>
void merge_sort_bottomup(RanIt b, RanIt e, Cmp c);

template <class RanIt>
void merge_sort_bottomup(RanIt b, RanIt e);

// container versions

template <class Cont, class Cmp>
void merge_sort_bottomup(Cont& v, Cmp c);

template <class Cont>
void merge_sort_bottomup(Cont& v);


// implementation

#include <merge_sort_bottomup_impl.hpp>

#endif // MERGESORTBOTTOMUP_HPP_INCLUDED_
