# Copyright (c) 2011 Alexander Poluektov (alexander.poluektov@gmail.com)
#
# Use, modification and distribution are subject to the
# Boost Software License, Version 1.0. (See accompanying file
# LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

SOURCES=test/main.cpp test/test_heap_sort.cpp test/test_radix_sort.cpp \
        test/test_merge_sort.cpp test/test_merge_sort_bottomup.cpp \
        test/test_quick_sort.cpp

OBJECTS=$(SOURCES:.cpp=.o)

%.o: %.cpp
	g++ -Wall -c -Iinclude $< -o $@

test_sort: $(OBJECTS)
	g++ -o test_sort $(OBJECTS) -lboost_unit_test_framework

all: test_sort

check: all
	./test_sort

clean:
	rm -f test/*.o core
