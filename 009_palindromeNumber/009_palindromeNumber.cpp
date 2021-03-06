//
//  009_palindromeNumber.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

/*
 Determine whether an integer is a palindrome. Do this without extra space.
 
 click to show spoilers.
 
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 
 There is a more generic way of solving this problem.
 */

#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0) return false;
        
        int x_rev = 0;
        int x_org = x;
        
        while (x != 0) {
            x_rev = x_rev * 10 + (x % 10);
            x /= 10;
        }
        
        return (x_rev == x_org);
        
    }
    
    
    bool isPalindrome2(int x) {
        if (x == 0) return true;
        if (x < 0) return false;
        
        int len = 1;
        int x_len = x;
        while (x_len >= 10) {
            len *= 10;
            x_len /= 10;
        }
        
        int l, r;
        
        while (x != 0) {
            r = x % 10;
            l = x / len;
            
            if (r != l) return false;
            x = (x % len) / 10;
            len /= 100;
        }
        
        return true;
        
    }
 
};