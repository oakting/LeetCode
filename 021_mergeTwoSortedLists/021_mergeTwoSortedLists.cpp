//
//  021_mergeTwoSortedLists.cpp
//  LeetCode
//
//  Created by Oak on 9/23/15.
//
/*
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (!l1) return l2;
        else if (!l2) return l1;
        else {
            ListNode *head = NULL;
            ListNode *curr;;
            if (l1->val <= l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
            
            curr = head;
            
            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }
            
            if (l1) curr->next = l1;
            else if (l2) curr->next = l2;
            
            return head;
        }
        
    }
};