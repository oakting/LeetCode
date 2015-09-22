//
//  008_stringToIntegerAtoi.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

#include <stdio.h>
#include <climits>
#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        int i = 0;
        bool neg = false;
        
        // Remove excess space in front of the string
        while ((i < str.size()) && (str[i] == ' ')) i++;
        
        // Check if the number is neg or pos
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            neg = true;
            i++;
        }
        
        int result = 0;
        int max_lim = INT_MAX/10;
        int min_lim = INT_MIN/10;
        
        //for (; i < str.size(); ++i) {
        while (isdigit(str[i])) {
            if (neg) {
                if ((-result < min_lim) ||
                    ((-result == min_lim) && (int(str[i] - '0') > 8))) return INT_MIN;
            } else {
                if ((result > max_lim) ||
                    ((result == max_lim) && (int(str[i] - '0') > 7))) return INT_MAX;
            }
            
            result = result * 10 + (str[i] - '0');
            i++;
        }
        
        /*
         // Remove trailing spaces
         while ((i < str.size()) && (str[i] == ' ')) i++;
         
         // If there are other chars after removing trailing spaces, not a valid string
         if (i != str.size()) return 0;
         */
        
        // compute the final result
        if (neg) result = result * (-1);
        
        return result;
    }
};