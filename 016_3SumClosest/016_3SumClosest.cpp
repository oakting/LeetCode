//
//  016_3SumClosest.cpp
//  LeetCode
//
//  Created by Oak on 9/23/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>


using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;  // store the minimum difference
        int result = 0;          // store the closest result
        
        if (nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1;
            int end = nums.size() - 1;
            
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(target - sum);
                
                if (diff == 0) return sum;
                
                if (diff < min_diff) {
                    min_diff = diff;
                    result = sum;
                }
                
                if (sum < target) start++;
                else end--;
            }
        }
        
        return result;
    }
};