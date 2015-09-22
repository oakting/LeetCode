//
//  010_regularExpressionMatching.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p.size() == 0) return (s.size() == 0);
        
        if (p[1] != '*') { // single char matching base case
            if ((p[0] == s[0]) || ((p[0] == '.') && (s[0] != '\0'))) {
                return isMatch(s.substr(1), p.substr(1));
            } else {
                return false;
            }
        }
        
        int i = 0;
        while ((p[0] == s[i]) || ((p[0] == '.') && (s[i] != '\0'))) {
            if (isMatch(s, p.substr(2))) return true;
            ++i;
        }
        
        //cout << "s.substr(i) : " << s.substr(i) << "  p.substr(2) : " << p.substr(2) << endl;
        
        return isMatch(s.substr(i), p.substr(2));
    }
    
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return (*s == '\0');
        
        if (*(p+1) != '*') {
            if ((*p == *s) || ((*p == '.') && (*s != '\0')))
                return isMatch(s+1, p+1);
            else
                return false;
        }
        
        while ((*p == *s) || ((*p == '.') && (*s != '\0'))) {
            if (isMatch(s, p+2)) return true;
            ++s;
        }
        
        return isMatch(s, p+2);
    }
};

