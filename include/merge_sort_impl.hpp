// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef MERGESORTIMPL_HPP_INCLUDED_
#define MERGESORTIMPL_HPP_INCLUDED_

#include <vector>
#include <cstddef>
#include <algorithm>
#include <functional>


namespace merge_sort_aux
{

template <class RanIt, class Cmp, class T>
inline
void merge(RanIt b, RanIt m, RanIt e, Cmp const& c, std::vector<T>& buf)
{
    std::copy(b, e, buf.begin());

    RanIt i1 = buf.begin();
    RanIt const e1 = buf.begin() + std::distance(b, m);

    RanIt i2 = e1;
    RanIt const e2 = buf.begin() + std::distance(b, e);

    RanIt k = b;

    while (i1 != e1 && i2 != e2)
        if (c(*i1, *i2))
            *k++ = *i1++;
        else
            *k++ = *i2++;

    while (i1 != e1)
        *k++ = *i1++;

    while (i2 != e2)
        *k++ = *i2++;
}

template <class RanIt, class Cmp, class T>
inline
void merge_sort_impl(RanIt b, RanIt e, Cmp const& c, std::vector<T>& buf)
{
    if (b == e || b + 1 == e)
        return;

    RanIt m = b + (std::distance(b, e) + 1) / 2;

    merge_sort_impl(b, m, c, buf);
    merge_sort_impl(m, e, c, buf);
    merge(b, m, e, c, buf);
}

} // namespace merge_sort_aux

// iterators versions

template <class RanIt, class Cmp>
inline
void merge_sort(RanIt b, RanIt e, Cmp c)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    std::vector<T> buf(std::distance(b, e)); // could use scoped_array instead
    merge_sort_aux::merge_sort_impl(b, e, c, buf);
}

template <class RanIt>
inline
void merge_sort(RanIt b, RanIt e)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    return merge_sort(b, e, std::less<T>());
}

// container versions

template <class Cont, class Cmp>
inline
void merge_sort(Cont& v, Cmp c)
{
    return merge_sort(v.begin(), v.end(), c);
}


template <class Cont>
inline
void merge_sort(Cont& v)
{
    return merge_sort(v.begin(), v.end());
}

#endif // MERGESORTIMPL_HPP_INCLUDED_
