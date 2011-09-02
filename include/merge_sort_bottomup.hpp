// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef MERGESORTBOTTOMUP_HPP_INCLUDED_
#define MERGESORTBOTTOMUP_HPP_INCLUDED_

#include <vector>
#include <cstddef>
#include <algorithm>
#include <functional>


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

namespace merge_sort_bottomup_aux
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

} // namespace merge_sort_bottomup_aux

// iterators versions

template <class RanIt, class Cmp>
inline
void merge_sort_bottomup(RanIt b, RanIt e, Cmp c)
{
    using merge_sort_bottomup_aux::merge;

    typedef typename std::iterator_traits<RanIt>::value_type T;
    std::vector<T> buf(std::distance(b, e)); // scoped_array?

    for (int i = 1; i < e - b; i *= 2)
        for (int j = 0; j < e - b - i; j += 2*i)
            merge(b+j, b+j+i, std::min(b+j+2*i, e), c, buf);
}

template <class RanIt>
inline
void merge_sort_bottomup(RanIt b, RanIt e)
{
    typedef typename std::iterator_traits<RanIt>::value_type T;
    return merge_sort_bottomup(b, e, std::less<T>());
}

// container versions

template <class Cont, class Cmp>
inline
void merge_sort_bottomup(Cont& v, Cmp c)
{
    return merge_sort_bottomup(v.begin(), v.end(), c);
}

template <class Cont>
inline
void merge_sort_bottomup(Cont& v)
{
    return merge_sort_bottomup(v.begin(), v.end());
}



#endif // MERGESORTBOTTOMUP_HPP_INCLUDED_
