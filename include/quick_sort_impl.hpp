// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QUICKSORTIMPL_HPP_INCLUDED_
#define QUICKSORTIMPL_HPP_INCLUDED_

#include <cstddef>
#include <algorithm>
#include <functional>


namespace quick_sort_aux
{

template <class RanIt, class Cmp>
inline
RanIt part(RanIt b, RanIt e, Cmp c)
{
    using std::swap;

    typedef typename std::iterator_traits<RanIt>::value_type T;
    T const& pivot = *(e-1);

    RanIt i  = b;
    RanIt ip = b;
 
    for ( ; i != e-1; ++i) {
        if (c(*i, pivot)) {
            swap(*i, *ip);
            ++ip;
        }
    }
    swap(*ip, *(e-1));

    return ip;
}



template <class RanIt, class Cmp>
inline
void quick_sort_impl(RanIt b, RanIt e, Cmp c)
{
    if (e - b <= 1)
        return;

    RanIt i = part(b, e, c);

    quick_sort_impl(b, i, c);
    quick_sort_impl(i, e, c);
}

} // namespace quick_sort_aux

// iterators versions

template <class RanIt, class Cmp>
inline
void quick_sort(RanIt b, RanIt e, Cmp c)
{
    return quick_sort_aux::quick_sort_impl(b, e, c);
}

template <class RanIt>
inline
void quick_sort(RanIt b, RanIt e)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    return quick_sort(b, e, std::less<T>());
}

// container versions

template <class Cont, class Cmp>
inline
void quick_sort(Cont& v, Cmp c)
{
    return quick_sort(v.begin(), v.end(), c);
}


template <class Cont>
inline
void quick_sort(Cont& v)
{
    return quick_sort(v.begin(), v.end());
}

#endif // QUICKSORTIMPL_HPP_INCLUDED_
