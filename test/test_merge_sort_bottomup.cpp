// Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "merge_sort_bottomup.hpp"

#include "helpers.hpp"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/auto_unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_merge_sort_bottomup);

BOOST_AUTO_TEST_CASE(random)
{
    std::vector<size_t> v;
    generate_random(v, 1000, 1<<20);

    merge_sort_bottomup(v);

    BOOST_CHECK(check_sorted(v));
}

BOOST_AUTO_TEST_SUITE_END();
