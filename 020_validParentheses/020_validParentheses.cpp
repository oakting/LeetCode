//
//  020_validParentheses.cpp
//  LeetCode
//
//  Created by Oak on 9/23/15.
//
/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool isValid(string s) {    // Actually take into account of not parentheses characters
        vector<char> brackets;
        
        for (int i = 0; i < s.size(); ++i) {
            if ( (s[i] == '(') || (s[i] == '[') || (s[i] == '{') ) {
                brackets.push_back(s[i]);
            } else if ( (s[i] == ')') || (s[i] == ']') || (s[i] == '}') ) {
                char b = getPair(s[i]);
                if ((brackets.size() == 0) || (b != brackets.back())) {
                    return false;
                } else {
                    brackets.pop_back();
                }
            }
        }
        
        if (brackets.size() != 0) return false;
        
        return true;
    }
private:
    char getPair(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        
        return ' ';
    }
};