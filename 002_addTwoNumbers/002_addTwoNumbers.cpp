//
//  002_addTwoNumbers.cpp
//  LeetCode
//

#include <stdio.h>
#include "../LeetCode/Common.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode **curr = &head;
        int carry = 0;
        while (l1 || l2) {
            int val1 = 0, val2 = 0;
            
            val1 = getNextVal(l1);
            val2 = getNextVal(l2);
            
            int digit = val1 + val2 + carry;
            ListNode *newDigit = new ListNode(digit % 10);
            carry = digit / 10;
            
            *curr = newDigit;
            curr = &(newDigit->next);
        }
        
        if (carry)
            *curr = new ListNode(carry);
        
        return head;
    }
    
private:
    int getNextVal(ListNode* &l) {
        int val = 0;
        if (l != NULL) {
            val = l->val;
            l = l->next;
        }
        
        return val;
    }
};

