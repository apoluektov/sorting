// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef MERGESORT_HPP_INCLUDED_
#define MERGESORT_HPP_INCLUDED_

#include <vector>
#include <cstddef>
#include <algorithm>


namespace merge_sort_aux
{

inline
void merge(std::vector<size_t>& v, size_t low, size_t mid, size_t high,
           std::vector<size_t>& v1, std::vector<size_t>& v2)
{
    for (size_t i = low; i <= mid; ++i)
        v1[i-low] = v[i];
    for (size_t i = mid+1; i <= high; ++i)
        v2[i-mid-1] = v[i];

    size_t s1 = mid - low + 1;
    size_t s2 = high - mid;

    size_t i1 = 0;
    size_t i2 = 0;
    size_t i = low;

    while (i1 != s1 && i2 != s2)
        if (v1[i1] < v2[i2])
            v[i++] = v1[i1++];
        else
            v[i++] = v2[i2++];

    while (i1 != s1)
        v[i++] = v1[i1++];

    while (i2 != s2)
        v[i++] = v2[i2++];
}

inline
void merge_sort_impl(std::vector<size_t>& v, size_t low, size_t high,
                     std::vector<size_t>& v1, std::vector<size_t>& v2)
{
    if (low == high)
        return;

    size_t mid = (low + high) / 2;
    merge_sort_impl(v, low, mid, v1, v2);
    merge_sort_impl(v, mid+1, high, v1, v2);
    merge(v, low, mid, high, v1, v2);
}

} // namespace merge_sort_aux

inline
void merge_sort(std::vector<size_t>& v)
{
    std::vector<size_t> v1(v.size());
    std::vector<size_t> v2(v.size());
    merge_sort_aux::merge_sort_impl(v, 0, v.size()-1, v1, v2);
}

#endif // MERGESORT_HPP_INCLUDED_
