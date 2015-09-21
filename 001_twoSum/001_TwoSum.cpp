//
//  001_TwoSum.cpp
//  LeetCode
//
//  Created by Hans Ting on 9/19/15.
//  Copyright (c) 2015 Hans Ting. All rights reserved.
//


/* 
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
*/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

// Recursive Method
// O(n^2)
class Solution_001_1 {
public:
    
    bool twoSumHelper(vector<int>& nums, int target, int idx, vector<int>& sol) {
        if (sol.size() == 2) {
            if (target == (nums[sol[0]] + nums[sol[1]])) {
                return true;
            } else {
                return false;
            }
        } else if (nums.size() == idx) {
            return false;
        } else {
            sol.push_back(idx++);
            if (twoSumHelper(nums, target, idx, sol)) return true;
            sol.pop_back();
            if (twoSumHelper(nums, target, idx, sol)) return true;
        }
        
        return false;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        if (twoSumHelper(nums, target, 0, sol)) {
            sol[0]++;            sol[1]++;
        }
        
        return sol;
    }
};


// Use unordered_map

class Solution_001_2 {
public:
    // Use unordered_map for O(1)
    // Traverse through the array, and
    // Use (target - value) as the key, and the idx as value in the map
    // For each value in the array, find the map contains any other value
    // that would add up to the target value.
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_result;
        vector<int> sol;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (num_result.find(nums[i]) != num_result.end()) {
                sol.push_back(num_result[nums[i]] + 1);
                sol.push_back(i + 1);
                break;
            } else {
                num_result[target - nums[i]] = i;
            }
        }
        
        return sol;
        
    }
};







