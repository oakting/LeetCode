//
//  017_letterCombinationsOfaPhoneNumber.cpp
//  LeetCode
//
//  Created by Oak on 9/24/15.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    
    void letterCombHelper(vector<string> &result, string digits, int di, string &s) {
        if (digits.size() == di) {
            // When digits string is exhausted, push the result.
            result.push_back(s);
        } else {
            string chars= getCharsFromKey(digits[di]);
            for (int i = 0; i < chars.size(); ++i) {
                s.push_back(chars[i]);
                letterCombHelper(result, digits, di+1, s);
                s.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        
        string s;   // Temp storage for result
        letterCombHelper(result, digits, 0, s);
        
        return result;
    }
private:
    string getCharsFromKey(char key) {
        switch (key) {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default:  return "";
        }
    }
};