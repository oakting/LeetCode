//
//  260_singleNumberIII.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//
/*
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 
 For example:
 
 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 
 Note:
 The order of the result is not important. So in the above example, [5, 3] is also correct.
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int allxor = 0;
    int mask = 0;
    int x = 0, y = 0;
    int *sol;
    
    for (int i = 0; i < numsSize; ++i) {
        allxor ^= nums[i];
    }
    
    mask = allxor & ~(allxor - 1);    // use least sig bit as a mask to divide the two numbers
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & mask)     x ^= nums[i];
        else                    y ^= nums[i];
    }
    
    *returnSize = 2;
    sol = (int *)malloc(sizeof(int) * 2);
    
    *sol = x;
    *(sol+1) = y;
    
    return sol;
}

