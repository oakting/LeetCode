//
//  003_longestSubstringWithoutRepeatedCharacters.cpp
//  LeetCode
//

/*
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <stdio.h>
#include <set>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    // Not efficient method. Used set to record occurance of characters in the current string
    int lengthOfLongestSubstring(string s) {
        string currStr;
        set<char> freq;
        size_t currLen = 0;
        size_t longest = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (freq.find(s[i]) != freq.end()) {    // Found repeated char
                // Check if the currLen is longer
                if (currLen > longest) longest = currLen;
                
                // Find the index of the repeated char, and remove every char
                // before the index from the set
                size_t cIdx = currStr.find(s[i]);
                for (size_t j = 0; j <= cIdx; ++j) {
                    freq.erase(currStr[j]);
                }
                
                currStr = currStr.substr(cIdx + 1);
                currLen = currStr.length();
            }
            
            currLen++;
            currStr += s[i];
            freq.insert(s[i]);
        }
        
        if (currLen > longest) longest = currLen;
        
        return (int)longest;
    }
    
    int lengthOfLongestSubstring2(string s) {
        map<char, int> freq;
        int longest = 0;
        int lastRepeatedPos = -1;
        int i = 0;
        
        for (i = 0; i < s.length(); ++i) {
            if ((freq.find(s[i]) != freq.end()) && (lastRepeatedPos < freq[s[i]])) {
                lastRepeatedPos = freq[s[i]];
            }
            
            if (i - lastRepeatedPos > longest) {
                longest = i - lastRepeatedPos;
            }
            
            freq[s[i]] = i;
        }
        
        return longest;
    }
    
    // Don't use map
#define MAX_CHAR 256
    int lengthOfLongestSubstring3(string s) {
        int charset[MAX_CHAR];
        memset(charset, -1, MAX_CHAR * sizeof(int));
        int longest = 0;
        int lastRepeatedPos = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            if ((charset[s[i]] != -1) && (lastRepeatedPos < charset[s[i]])) {
                lastRepeatedPos = charset[s[i]];
            }
            
            if (i - lastRepeatedPos > longest) {
                longest = i - lastRepeatedPos;
            }
            
            charset[s[i]] = i;
        }
        
        return longest;
    }
    
    
};