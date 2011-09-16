// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QUICKSORTITERATIVEIMPL_HPP_INCLUDED_
#define QUICKSORTITERATIVEIMPL_HPP_INCLUDED_

#include <cstddef>
#include <algorithm>
#include <functional>
#include <stack>


namespace quick_sort_iterative_aux
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

    for ( ; i != e-1; ++i)
    {
        if (c(*i, pivot))
        {
            swap(*i, *ip);
            ++ip;
        }
    }
    swap(*ip, *(e-1));

    return ip;
}


template <class RanIt, class Cmp>
inline
void quick_sort_iterative_impl(RanIt b, RanIt e, Cmp c)
{
    if (e - b <= 1) return;

    std::stack<RanIt> arr;
    arr.push(b);
    arr.push(e);

    while (!arr.empty())
    {
        RanIt e1 = arr.top();
        arr.pop();
        RanIt b1 = arr.top();
        arr.pop();

        RanIt p = part(b1, e1, c);
        if (b1 < p)
        {
            arr.push(b1);
            arr.push(p);
        }

        if (p < e1-1)
        {
            arr.push(p);
            arr.push(e1);
        }
    }
}

} // namespace quick_sort_aux

// iterators versions

template <class RanIt, class Cmp>
inline
void quick_sort_iterative(RanIt b, RanIt e, Cmp c)
{
    return quick_sort_iterative_aux::quick_sort_iterative_impl(b, e, c);
}

template <class RanIt>
inline
void quick_sort_iterative(RanIt b, RanIt e)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    return quick_sort_iterative(b, e, std::less<T>());
}

// container versions

template <class Cont, class Cmp>
inline
void quick_sort_iterative(Cont& v, Cmp c)
{
    return quick_sort_iterative(v.begin(), v.end(), c);
}


template <class Cont>
inline
void quick_sort_iterative(Cont& v)
{
    return quick_sort_iterative(v.begin(), v.end());
}

#endif // QUICKSORTITERATIVEIMPL_HPP_INCLUDED_
