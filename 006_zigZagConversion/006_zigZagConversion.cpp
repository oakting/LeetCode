//
//  006_zigZagConversion.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

#include <stdio.h>
#include <string>

using std::string;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string *nStr = new string[numRows];
        
        bool rowInc = true;
        int rowIdx = 0;
        for (int i = 0; i < s.size(); ++i) {
            nStr[rowIdx] += s[i];
            
            if (rowIdx == (numRows - 1)) rowInc = false;
            if (rowIdx == 0) rowInc = true;
            
            if (rowInc) ++rowIdx;
            else --rowIdx;
            
        }
        
        string result;
        for (int i = 0; i < numRows; ++i) {
            result += nStr[i];
        }
        
        delete[] nStr;
        
        return result;
    }
};