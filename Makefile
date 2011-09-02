# Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
#
# Use, modification and distribution are subject to the
# Boost Software License, Version 1.0. (See accompanying file
# LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

heap_sort_test: heap_sort_test.o
	g++ -o heap_sort_test heap_sort_test.o

heap_sort_test.o: test/heap_sort_test.cpp
	g++ -Wall -c -o heap_sort_test.o test/heap_sort_test.cpp -Iinclude

merge_sort_test: merge_sort_test.o
	g++ -o merge_sort_test merge_sort_test.o

merge_sort_test.o: test/merge_sort_test.cpp
	g++ -Wall -c -o merge_sort_test.o test/merge_sort_test.cpp -Iinclude

merge_sort_bottomup_test: merge_sort_bottomup_test.o
	g++ -o merge_sort_bottomup_test merge_sort_bottomup_test.o

merge_sort_bottomup_test.o: test/merge_sort_bottomup_test.cpp
	g++ -Wall -c -o merge_sort_bottomup_test.o test/merge_sort_bottomup_test.cpp -Iinclude

all: heap_sort_test merge_sort_test merge_sort_bottomup_test

check: all
	./heap_sort_test
	./merge_sort_test
	./merge_sort_bottomup_test

clean:
	rm -f *.o core
