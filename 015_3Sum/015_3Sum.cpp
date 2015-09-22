//
//  015_3Sum.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> res_m;
        vector<vector<int>> res;
        //vector<int>::iterator it1,it2,it3,iend;
        
        if (nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if ((i == 0) || (nums[i] > nums[i-1])) {    // Avoid duplicate items in the nums
                int negate = -nums[i];
                
                int start = i + 1;
                int end = nums.size() - 1;
                
                while (start < end) {
                    // Case 1 - found a solution
                    if (negate == (nums[start] + nums[end])) {
                        res_m.push_back(nums[i]);
                        res_m.push_back(nums[start]);
                        res_m.push_back(nums[end]);
                        res.push_back(res_m);
                        res_m.clear();
                        start++;
                        end--;
                        
                        while ((start < end) && (nums[start] == nums[start - 1])) start++;
                        while ((start < end) && (nums[end] == nums[end + 1])) end--;
                    }
                    // Case 2 - summation result is greater than negate, move end
                    else if (negate < (nums[start] + nums[end])) {
                        end--;
                        while ((start < end) && (nums[end] == nums[end + 1])) end--;
                    }
                    // Case 3 - summation result is smaller than negate, move start
                    else if (negate > (nums[start] + nums[end])) {
                        start++;
                        while ((start < end) && (nums[start] == nums[start - 1])) start++;
                    }
                }
            }
        }
        
        return res;
    }
};