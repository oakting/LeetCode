//
//  190_reverseBits.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15
//

/* 
 Reverse bits of a given 32 bits unsigned integer.
 
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 
 Follow up:
 If this function is called many times, how would you optimize it?
 
 Related problem: Reverse Integer
 */

#include <stdio.h>
#include "../LeetCode/Common_C.h"


// Compare bits from outer to inner
uint32_t reverseBits_bitCmp(uint32_t n) {
    int i = 0, j = 31;
    while (i < j) {
        if (((n >> i) & 1) != ((n >> j) & 1)) {
            // if not equal, use xor to flip bits
            n ^= ((1U << i) | (1U << j));
        }
        i++, j--;
    }
    return n;
}

// Flip with neighbors
uint32_t reverseBits_swap(uint32_t x) {
    {
        x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
        x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
        x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
        x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
        return ((x >> 16) | (x << 16));
    }
}

// Brute force
uint32_t reverseBits_bf(uint32_t n) {
    uint32_t nr = 0;
    int j = 31;
    for (int i = 0; i < 32; ++i) {
        uint32_t bit = (n & (1 << i)) >> i;
        nr |= (bit << j);
        j--;
    }
    
    return nr;
}

