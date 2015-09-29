//
//  026_removeDuplicatesFromSortedArray.cpp
//  LeetCode
//
//  Created by Oak on 9/25/15.
//
/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array nums = [1,1,2],
 
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // if vector size is smaller or equal to 1, there is no duplicate
        if (nums.size() <= 1) return nums.size();
        
        // destiation is index 1, because index 0 is not a duplicate
        int dst = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[dst - 1])   // if curr is not equal to the previous one, store!
                nums[dst++] = nums[i];
        }
        
        return dst;
    }
};