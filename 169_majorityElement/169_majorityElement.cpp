//
//  169_majorityElement.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

/*
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <stdio.h>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int major_lim = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]] = map[nums[i]] + 1;
            }
            
            if (map[nums[i]] > major_lim) return nums[i];
        }
        
        return 0;
    }
    
    // Moore Voting Algorithm
    // Refer to:
    // http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
    int majorityElement(int* nums, int numsSize) {
        int majority;
        int count = 0;
        int limit = numsSize / 2;
        
        for (int i = 0; i < numsSize; ++i) {
            if (count == 0) {
                majority = nums[i];
                ++count;
            } else {
                if (majority == nums[i]) {
                    ++count;
                    if (count > limit) return majority;
                }
                else --count;
            }
        }
        
        return majority;
    }
};