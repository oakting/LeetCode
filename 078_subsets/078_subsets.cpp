//
//  078_subsets.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <vector>

using std::vector;

class Solution {
public:
    void findSubsets(vector<int>& nums, int ni, vector<int> &set, vector<vector<int>> &sol) {
        if (ni == nums.size()) {
            sol.push_back(set);
        } else {
            set.push_back(nums[ni++]);
            findSubsets(nums, ni, set, sol);
            set.pop_back();
            findSubsets(nums, ni, set, sol);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> set;
        if (nums.size() == 0) return sol;
        sort(nums.begin(), nums.end());
        
        findSubsets(nums, 0, set, sol);
        
        return sol;
    }
};