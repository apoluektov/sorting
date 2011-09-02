// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "merge_sort.hpp"

#include <cstdlib>


void generate_random(std::vector<size_t>& v, size_t n, size_t max)
{
    for (size_t i = 0; i < n; ++i) {
        v.push_back(rand() % max);
    }
}


bool check_sorted(std::vector<size_t> const& v)
{
    size_t const size = v.size();
    for (size_t i = 1; i < size; ++i) {
        if (v[i] < v[i-1]) return false;
    }
    return true;
}


int main()
{
    std::vector<size_t> v;
    generate_random(v, 1000, 1<<20);

    merge_sort(v);

    if (check_sorted(v))
        return 0;
    else
        return 1;
}
