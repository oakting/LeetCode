//
//  012_integerToRoman.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <string>

using std::string;

// 1        - I
// 5        - V
// 10       - X
// 50       - L
// 100      - C
// 500      - D
// 1000     - M


class Solution {
public:
    //greeding algorithm
    string intToRoman(int num) {
        string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        string result;
        
        for(int i = 0; num != 0; i++){
            while(num >= value[i]){
                num -= value[i];
                result += symbol[i];
            }
        }
        
        return result;
    }
    
    //original implementation
    string intToRoman2(int num) {
        string result;
        int base = 1;
        int tmp = num;
        while (tmp / 10) {
            base *= 10;
            tmp /= 10;
        }
        
        while (num) {
            int digit = num / base;
            
            result = result + digitToRoman(digit, base);
            num = (num % base);
            base /= 10;
        }
        
        return result;
    }
private:
    string digitToRoman(int digit, int base) {
        char *romanTable[4] = {"IVX", "XLC", "CDM", "M??"};
        int tableIdx = -1;
        
        if (digit == 0) return "";
        
        while (base) {
            base = base / 10;
            tableIdx++;
        }
        
        string romanStr;
        if (digit <= 3) {
            romanStr = string(digit, romanTable[tableIdx][0]);
        } else if (digit <= 4) {
            romanStr = string(1, romanTable[tableIdx][0]) + string(1, romanTable[tableIdx][1]);
        } else if (digit <= 8) {
            romanStr = string(1, romanTable[tableIdx][1]);
            romanStr += string((digit - 5), romanTable[tableIdx][0]);
        }
        else if (digit == 9) {
            romanStr = string(1, romanTable[tableIdx][0]) + string(1, romanTable[tableIdx][2]);
        }
        else if (digit == 10) {
            romanStr = string(1, romanTable[tableIdx][2]);
        }
        
        return romanStr;
        
    }
};