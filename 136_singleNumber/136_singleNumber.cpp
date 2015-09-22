//
//  136_singleNumber.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            single ^= nums[i];
        }
        
        return single;
    }
};