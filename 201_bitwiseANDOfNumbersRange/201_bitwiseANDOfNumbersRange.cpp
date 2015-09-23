//
//  201_bitwiseANDOfNumbersRange.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//  Copyright (c) 2015 Hans Ting. All rights reserved.
//

#include <stdio.h>



int rangeBitwiseAnd(int m, int n) {
    int mask = 0xffffffff;
    
    /* find out the same bits in left side of m an n*/
    while (mask != 0) {
        if ((m & mask) == (n & mask)) {
            break;
        }
        mask <<= 1;
    }
    
    return m & mask;
    
}

/*
 int rangeBitwiseAnd(int m, int n) {
     int i = 0;
     int result = m & n;
     
     if (m == n) return result;
     
     while (result && ((m + (1 << i)) < n)) {
     result &= ~(1 << i);
     i++;
     }
     
     return result;
 }
 */