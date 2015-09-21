//
//  007_reverseInteger.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//  Copyright (c) 2015 Hans Ting. All rights reserved.
//

#include <stdio.h>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        
        while (x != 0) {
            if (y > INT_MAX/10 || y < INT_MIN/10){
                return 0;
            }
            y = y * 10 + (x % 10);
            x /= 10;
        }
        
        return y;
    }
};