//
//  024_swapNodesInPairs.cpp
//  LeetCode
//
//  Created by Oak on 9/29/15.
//
/*
 Given a linked list, swap every two adjacent nodes and return its head.
 
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode *prevNode = NULL;
        ListNode *curr = head;
        ListNode *tmp;
        
        while ((curr) && (curr->next)) {
            // Swap curr and bNode
            tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = curr;
            
            if (prevNode == NULL) head = tmp;
            else                  prevNode->next = tmp;
            
            // Update
            prevNode = curr;
            curr = curr->next;;
        }
        
        return head;
    }
};


