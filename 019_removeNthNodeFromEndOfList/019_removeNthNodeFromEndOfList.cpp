//
//  019_removeNthNodeFromEndOfList.cpp
//  LeetCode
//
//  Created by Oak on 9/23/15.
//
/*
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 */

#include <stdio.h>
#include "../LeetCode/Common_C.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode * fast = head;
    struct ListNode * pre_k = head;
    struct ListNode * remove;
    
    // If n = 0 or list is empty, return the original list.
    if ((n == 0) || (!head)) return head;
    
    // Travel the fast node for n steps or until fast is NULL
    while (n && fast) {
        fast = fast->next;
        --n;
    }
    
    // fast reaches NULL before n = 0, not a valid n
    if (n != 0) { return head; }
    
    // [special case] if n is 0 and fast is NULL, means the removing node is head!
    if ((n == 0) && (fast == NULL)) {
        head = head->next;
        free(pre_k);
        return head;
    }
    
    // travel both fast and pre_k
    while (fast->next) {
        fast = fast->next;
        pre_k = pre_k->next;
    }
    
    // remove the node after pre_k
    remove = pre_k->next;
    pre_k->next = remove->next;
    free(remove);
    
    return head;
}