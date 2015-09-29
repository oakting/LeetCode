//
//  022_generateParentheses.cpp
//  LeetCode
//
//  Created by Oak on 9/29/15.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void genParenthesisHelper( vector<string> &pars, string &sofar, int lpcnt, int n) {
        if (sofar.size() == (2 * n)) {
            pars.push_back(sofar);
        } else {
            if (lpcnt < n) {
                sofar.push_back('(');
                genParenthesisHelper(pars, sofar, lpcnt + 1, n);
                sofar.pop_back();
            }
            
            if ((sofar.size() - lpcnt) < lpcnt) {
                sofar.push_back(')');
                genParenthesisHelper(pars, sofar, lpcnt, n);
                sofar.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> pars;
        string sofar;
        genParenthesisHelper(pars, sofar, 0, n);
        return pars;
    }
};