//
//  137_singleNumberII.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int two = 0;
    int one = 0;
    int mask = 0;
    for (int i = 0; i < numsSize; ++i) {
        two = two | (one & nums[i]);
        one ^= nums[i];
        mask = ~(one & two);
        one &= mask;
        two &= mask;
    }
    
    return one;
}
