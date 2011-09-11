# Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
#
# Use, modification and distribution are subject to the
# Boost Software License, Version 1.0. (See accompanying file
# LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

test_heap_sort.o: test/test_heap_sort.cpp
	g++ -Wall -c -o test_heap_sort.o test/test_heap_sort.cpp -Iinclude

test_merge_sort.o: test/test_merge_sort.cpp
	g++ -Wall -c -o test_merge_sort.o test/test_merge_sort.cpp -Iinclude

test_merge_sort_bottomup.o: test/test_merge_sort_bottomup.cpp
	g++ -Wall -c -o test_merge_sort_bottomup.o test/test_merge_sort_bottomup.cpp -Iinclude

test_radix_sort.o: test/test_radix_sort.cpp
	g++ -Wall -c -o test_radix_sort.o test/test_radix_sort.cpp -Iinclude

main.o: test/main.cpp
	g++ -Wall -c -o main.o test/main.cpp

test_sort: test_heap_sort.o test_merge_sort.o test_merge_sort_bottomup.o test_radix_sort.o main.o
	g++ -o test_sort main.o test_merge_sort.o test_merge_sort_bottomup.o test_radix_sort.o -lboost_unit_test_framework

all: test_sort

check: all
	./test_sort

clean:
	rm -f *.o core
