//
//  231_powerOfTwo.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//
/*
 Given an integer, write a function to determine if it is a power of two.
 */
#include <stdio.h>


bool isPowerOfTwo(int n) {
    if ((n == 0) || (n < 0)) return false;
    
    return !(n & (n - 1));
}

