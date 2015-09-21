//
//  002_addTwoNumbers.c
//  LeetCode
//

#include <stdio.h>
#include "../LeetCode/Common_C.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getNextVal(struct ListNode** l) {
    int val = 0;
    if (*l != NULL) {
        val = (*l)->val;
        *l = (*l)->next;
    }
    
    return val;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode **curr = &head;
    int carry = 0;
    while (l1 || l2) {
        int val1 = 0, val2 = 0;
        
        val1 = getNextVal(&l1);
        val2 = getNextVal(&l2);
        
        int digit = val1 + val2 + carry;
        struct ListNode *newDigit = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (newDigit == NULL) return NULL;
        
        newDigit->val = digit % 10;
        carry = digit / 10;
        
        *curr = newDigit;
        curr = &(newDigit->next);
    }
    
    if (carry) {
        struct ListNode *newDigit = malloc(sizeof(struct ListNode));
        if (newDigit == NULL) return NULL;
        newDigit->val = carry;
        *curr = newDigit;
    }
    
    return head;
}