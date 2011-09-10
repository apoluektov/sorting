// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) 

#ifndef HEAPSORTIMPL_HPP_INCLUDED_
#define HEAPSORTIMPL_HPP_INCLUDED_

#include <cstddef>
#include <algorithm>
#include <functional>


namespace heap_sort_aux 
{

template <class RanIt, class Comp>
inline
void make_heap(RanIt b, RanIt e, Comp cmp)
{
    size_t size = e - b;
    for (size_t i = 0; i < size; ++i) {
        // bubble up
        for (size_t j = i; j > 0; j = (j-1)/2) {
            if (!cmp(*(b + j), *(b + (j-1)/2)))
                std::swap(*(b + j), *(b + (j-1)/2));
            else
                break;
        }
    }
}

template <class RanIt, class Comp>
inline
void remove_root(RanIt b, RanIt e, Comp cmp)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;

    size_t size = e - b;
    std::swap(*b, *(e-1));
    for (size_t j = 0; j < size-1; ) {
        // bubble down
        T const& v1 = 2*j+1 < size-1 ? *(b + 2*j+1) : *(b + j);
        T const& v2 = 2*j+2 < size-1 ? *(b + 2*j+2) : *(b + j);

        if (cmp(*(b + j), v1) || cmp(*(b + j), v2)) {
            if (!cmp(v1, v2)) {
                std::swap(*(b + j), *(b + 2*j+1));
                j = 2*j + 1;
            }
            else {
                std::swap(*(b + j), *(b + 2*j+2));
                j = 2*j + 2;
            }
        }
        else {
            return;
        }
    }
}

} // namespace heap_sort_aux

template <class RanIt, class Comp>
inline
void heap_sort(RanIt b, RanIt e, Comp cmp)
{
    heap_sort_aux::make_heap(b, e, cmp);

    size_t size = e - b;
    for (size_t i = 0; i < size; ++i) {
        heap_sort_aux::remove_root(b, e-i, cmp);
    }
}

template <class RanIt>
inline
void heap_sort(RanIt b, RanIt e)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    return heap_sort(b, e, std::less<T>());
}

template <class Container>
inline
void heap_sort(Container& v)
{
    return heap_sort(v.begin(), v.end());
}

template <class Container, class Comp>
inline
void heap_sort(Container& v, Comp cmp)
{
    return heap_sort(v.begin(), v.end(), cmp);
}

#endif // HEAPSORTIMPL_HPP_INCLUDED_
