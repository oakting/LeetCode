//
//  268_missingNumber.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>

// Use expected sum - actual sum = missing number
int missingNumber_area(int* nums, int numsSize) {
    int sum = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }
    
    return ((1 + numsSize) * (numsSize)) / 2 - sum;
}


// Use XOR property
int missingNumber_xor(int* nums, int numsSize) {
    int res = numsSize;
    for (int i = 0; i < numsSize; ++i) {
        res ^= i;
        res ^= nums[i];
    }
    return res;
}