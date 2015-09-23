//
//  187_repeatedDNASequences.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_HashTable_Bit {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> strs;
        vector<string> repStrs;
        int n = s.size();
        
        for (int i = 0; i < (n - 9); ++i) {
            int key = getKey(s, i);
            if (strs.find(key) == strs.end()) strs[key] = 0;
            else {
                strs[key] = strs[key] + 1;
                if (strs[key] == 1) repStrs.push_back(s.substr(i, 10));
            }
        }
        
        return repStrs;
    }
    
private:
    int getKey(string s, int begin) {
        int b = 0;
        int end = begin + 10;
        long res = 0;
        for (int i = begin; i < end; ++i) {
            if      (s[i] == 'A') b |= 0x00;
            else if (s[i] == 'C') b |= 0x01;
            else if (s[i] == 'G') b |= 0x02;
            else if (s[i] == 'T') b |= 0x03;
            
            b <<= 2;
        }
        
        return b;
    }
};

class Solution_HashTable {
public:
    // Use map
    vector<string> findRepeatedDnaSequences_2(string s) {
        unordered_map<long, int> strs;
        vector<string> repStrs;
        int n = s.size();
        
        for (int i = 0; i < (n - 9); ++i) {
            long key = strToLong(s, i);
            if (strs.find(key) == strs.end()) strs[key] = 0;
            else strs[key] = strs[key] + 1;
        }
        
        for (auto it = strs.begin(); it != strs.end(); ++it) {
            if (it->second >= 1) {
                string s = longToStr(it->first);
                repStrs.push_back(s);
            }
        }
        
        return repStrs;
    }
    
private:
    long strToLong(string s, int begin) {
        long res = 0;
        for (int i = begin; i < (begin + 10); ++i) {
            if (s[i] == 'A') res = res * 10 + 1;
            else if (s[i] == 'C') res = res * 10 + 2;
            else if (s[i] == 'G') res = res * 10 + 3;
            else if (s[i] == 'T') res = res * 10 + 4;
        }
        
        return res;
    }
    
    string longToStr(long num) {
        string dna;
        
        while (num) {
            int n = num % 10;
            num = num / 10;
            if (n == 1) dna = "A" + dna;
            else if (n == 2) dna = "C" + dna;
            else if (n == 3) dna = "G" + dna;
            else if (n == 4) dna = "T" + dna;
        }
        
        return dna;
    }
};


class Solution_BruteForce {
public:
    // Brute force
    vector<string> findRepeatedDnaSequences(string s) {
        string cmp;
        vector<string> repStrs;
        
        if (s.size() < 20) return repStrs;
        
        for (int i = 0; i <= (s.size() - 20); ++i) {
            string cmp = s.substr(i, 10);
            for (int j = i + 10; j <= (s.size() - 10); ++j) {
                if (cmp == s.substr(j, 10)) repStrs.push_back(cmp);
            }
        }
        
        return repStrs;
    }
};