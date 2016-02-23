/*
 * qsort_vs_sort.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: oagomez
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <cstdlib>
#include <ctime>
#include <cstdio>

const size_t LARGE_SIZE = 100000 * 10;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

int main() {
    int ary[LARGE_SIZE];
    int ary_copy[LARGE_SIZE];
    // generate random data
    std::generate( ary, ary + LARGE_SIZE, rnd() );
    std::copy( ary, ary + LARGE_SIZE, ary_copy );
    std::cout << std::equal(std::begin(ary), std::end(ary), std::begin(ary_copy)) << std::endl;
    // get time
    std::time_t start = std::clock();
    // perform quick sort C using function pointer
    std::qsort( ary, LARGE_SIZE, sizeof( int ), comp );
    std::time_t end = std::clock();
    std::cout << "C quick-sort time elapsed  : " << static_cast<double>( end - start ) / CLOCKS_PER_SEC << "\n";
    // get time again
    start = std::clock();
    // perform quick sort C++ using function object
    std::sort( ary_copy, ary_copy + LARGE_SIZE );
    end = std::clock();
    std::cout << "C++ quick-sort time elapsed: " << static_cast<double>( end - start ) / CLOCKS_PER_SEC << "\n";

    std::cout << std::equal(std::begin(ary), std::end(ary), std::begin(ary_copy)) << std::endl;
}



