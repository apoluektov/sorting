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
void merge(std::vector<size_t>& v, size_t const low, size_t const mid, size_t const high,
           std::vector<size_t>& buf)
{
    for (size_t i = low; i <= high; ++i)
        buf[i] = v[i];

    size_t i1 = low;
    size_t const s1 = mid + 1;

    size_t i2 = mid + 1;
    size_t const s2 = high + 1;

    size_t k = low;

    while (i1 != s1 && i2 != s2)
        if (buf[i1] < buf[i2])
            v[k++] = buf[i1++];
        else
            v[k++] = buf[i2++];

    while (i1 != s1)
        v[k++] = buf[i1++];

    while (i2 != s2)
        v[k++] = buf[i2++];
}

inline
void merge_sort_impl(std::vector<size_t>& v, size_t const low, size_t const high,
                     std::vector<size_t>& buf)
{
    if (low == high)
        return;

    size_t const mid = (low + high) / 2;
    merge_sort_impl(v, low, mid, buf);
    merge_sort_impl(v, mid+1, high, buf);
    merge(v, low, mid, high, buf);
}

} // namespace merge_sort_aux

inline
void merge_sort(std::vector<size_t>& v)
{
    std::vector<size_t> buf(v.size());
    merge_sort_aux::merge_sort_impl(v, 0, v.size()-1, buf);
}

#endif // MERGESORT_HPP_INCLUDED_
