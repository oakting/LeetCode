//
//  014_longestCommonPrefix.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;


class Solution {
public:
    // Use strs[0] as the base string
    // Compare against all strings in the vectors for char 0.
    // If a not match is found, stop the iteration and return the
    // longest common prefix using the current index
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};