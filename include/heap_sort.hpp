// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) 

#ifndef HEAPSORT_HPP_INCLUDED_
#define HEAPSORT_HPP_INCLUDED_

#include <vector>
#include <cstddef>
#include <algorithm>


namespace heap_sort_aux 
{

inline
void make_heap(std::vector<size_t>& v)
{
    size_t size = v.size();
    for (size_t i = 0; i < size; ++i) {
        // bubble up
        for (size_t j = i; j > 0; j = (j - 1) / 2) {
            if (v[j] > v[(j-1)/2])
	      std::swap(v[j], v[(j-1)/2]);
            else
                break;
        }
    }
}

inline
void remove_root(size_t idx, std::vector<size_t>& v)
{
    size_t size = v.size();
    std::swap(v[0], v[size-idx-1]);

    for (size_t j = 0; j < size-idx-1; ) {
        // bubble down
        size_t v1 = 2*j+1 < size-idx-1 ? v[2*j+1] : v[j];
        size_t v2 = 2*j+2 < size-idx-1 ? v[2*j+2] : v[j];

        if (v[j] < v1 || v[j] < v2) {
            if (v1 >= v2) {
                std::swap(v[j], v[2*j+1]);
                j = 2*j + 1;
            }
            else {
                std::swap(v[j], v[2*j+2]);
                j = 2*j + 2;
            }
        }
        else {
            return;
        }
    }
}

} // namespace heap_sort_aux

inline
void heap_sort(std::vector<size_t>& v)
{
    heap_sort_aux::make_heap(v);

    size_t size = v.size();
    for (size_t i = 0; i < size; ++i) {
        heap_sort_aux::remove_root(i, v);
    }
}

#endif // HEAPSORT_HPP_INCLUDED_
