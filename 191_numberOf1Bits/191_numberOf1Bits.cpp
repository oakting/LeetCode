//
//  191_numberOf1Bits.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//  Copyright (c) 2015 Hans Ting. All rights reserved.
//

/*
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */
#include <stdio.h>
#include "../LeetCode/Common_C.h"

int hammingWeight(uint32_t n) {
    int num1s = 0;
    
    while (n != 0) {
        n = n & (n - 1);
        num1s++;
    }
    
    return num1s;
}