//
//  018_4Sum.cpp
//  LeetCode
//
//  Created by Oak on 9/24/15.
//
/*
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 
 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 
 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    
    // Use a set to avoid duplicate
    vector<vector<int>> fourSum_set(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<vector<int>> hashset;
        
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (nums.size() - 3); ++i) {
            for (int j = i + 1; j < (nums.size() - 2); ++j) {
                int start = j + 1;
                int end = nums.size() - 1;
                while (start < end) {
                    int tmpsum = nums[i] + nums[j] + nums[start] + nums[end];
                    if (tmpsum < target) {
                        ++start;
                    } else if (tmpsum > target) {
                        --end;
                    } else {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
                        res.push_back(nums[start]);
                        res.push_back(nums[end]);
                        
                        if (hashset.find(res) == hashset.end()) {
                            hashset.insert(res);
                            result.push_back(res);
                        }
                        ++start;
                        --end;
                    }
                }
            }
        }
        return result;
    }
    
    // Use iterative method, and check for values to avoid duplicate solution
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (nums.size() - 3); ++i) {
            if ((i == 0) || (nums[i] != nums[i-1])) {
                for (int j = i + 1; j < (nums.size() - 2); ++j) {
                    if ((j == (i + 1)) || (nums[j] != nums[j-1])) {
                        int start = j + 1;
                        int end = nums.size() - 1;
                        
                        while (start < end) {
                            if ((start == (j + 1)) || (nums[start] != nums[start-1])) {
                                int tmpsum = nums[i] + nums[j] + nums[start] + nums[end];
                                
                                if (tmpsum == target) {
                                    vector<int> res;
                                    res.push_back(nums[i]);
                                    res.push_back(nums[j]);
                                    res.push_back(nums[start]);
                                    res.push_back(nums[end]);
                                    result.push_back(res);
                                    
                                    ++start;
                                    --end;
                                } else if (tmpsum < target) {
                                    ++start;
                                } else {
                                    --end;
                                }
                            } else {
                                ++start;
                            }
                        }
                    }
                }
            }
        }
        
        return result;
    }
};