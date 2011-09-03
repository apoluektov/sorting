# Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
#
# Use, modification and distribution are subject to the
# Boost Software License, Version 1.0. (See accompanying file
# LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

test_heap_sort: test_heap_sort.o
	g++ -o test_heap_sort test_heap_sort.o -lboost_unit_test_framework

test_heap_sort.o: test/test_heap_sort.cpp
	g++ -Wall -c -o test_heap_sort.o test/test_heap_sort.cpp -Iinclude

test_merge_sort: test_merge_sort.o
	g++ -o test_merge_sort test_merge_sort.o -lboost_unit_test_framework

test_merge_sort.o: test/test_merge_sort.cpp
	g++ -Wall -c -o test_merge_sort.o test/test_merge_sort.cpp -Iinclude

test_merge_sort_bottomup: test_merge_sort_bottomup.o
	g++ -o test_merge_sort_bottomup test_merge_sort_bottomup.o -lboost_unit_test_framework

test_merge_sort_bottomup.o: test/test_merge_sort_bottomup.cpp
	g++ -Wall -c -o test_merge_sort_bottomup.o test/test_merge_sort_bottomup.cpp -Iinclude

all: test_heap_sort test_merge_sort test_merge_sort_bottomup

check: all
	./test_heap_sort
	./test_merge_sort
	./test_merge_sort_bottomup

clean:
	rm -f *.o core
