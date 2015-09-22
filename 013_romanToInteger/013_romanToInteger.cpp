//
//  013_romanToInteger.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
    
    int romanToInt(string s) {
        string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        int symbolSize = sizeof(value) / sizeof(value[0]);
        
        int result = 0;
        int i = 0;
        int symIdx = 0;
        
        for (symIdx = 0; symIdx < symbolSize; ++symIdx) {
            int symLen = symbol[symIdx].size();
            
            while (symbol[symIdx] == s.substr(i, symLen)) {
                result += value[symIdx];
                i += symLen;
            }
        }
        
        return result;
    }
    
    int romanToInt2(string s) {
        int prev = 0, total = 0;
        
        unordered_map<char, int> romanMap { { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int curr = romanMap[c];
            total += (curr > prev) ? (curr - 2 * prev) : curr;
            prev = curr;
        }
        return total;
        
    }
    

};