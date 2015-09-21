//
//  005_longestPalindromicSubstring.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

#include <stdio.h>
#include <string>

using std::string;


class Solution {
public:
    
    //O(N^22) time and O(1) space
    string findPalindrome(string s, int left, int right) {
        int len = s.size();
        while ((left >= 0) && (right <= (len - 1))) {
            if (s[left] != s[right]) break;
            left--;
            right++;
        }
        
        return s.substr(left + 1, right - left - 1);
    }
    
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        
        string longest;
        string str;
        for (int i = 0; i < s.size() - 1; ++i) {
            str = findPalindrome(s, i, i);
            if (str.size() > longest.size()) longest = str;
            
            str = findPalindrome(s, i, i + 1);
            if (str.size() > longest.size()) longest = str;
        }
        
        return longest;
    }
};
