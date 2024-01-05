//
//  list.cpp
//  Algorithm
//
//  Created by marco on 2019/8/28.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "list.hpp"
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Linked List Cycle (链表是否有环)
//LeetCode 141
//有环无环都会结束
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (slow!=NULL && fast!=NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast) {
            return true;
        }
    }
    return false;
}


//Intersection Of Two Linked Lists (两个链表是否有交点)
//LeetCode 160
//先计算长度，长的先遍历差值，再以前遍历比较
//length of linked list
int __calculateListLength(ListNode *head){
    
    int count = 0;
    
    while (head) {
        
        count++;
        head = head->next;
    }
    
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int lengthA = __calculateListLength(headA);
    int lengthB = __calculateListLength(headB);
    
    int n = lengthA - lengthB;
    
    ListNode *pA = headA;
    ListNode *pB = headB;
    
    //move node pointer
    for(int i=0; i < abs(n); i++){
        
        //a is longer
        if( n > 0){
            
            pA = pA->next;
            
        }else{
            //b is longer
            pB = pB->next;
            
        }
    }
    
    while (pA && pB) {
        
        //found intersection node
        if (pA == pB) {
            return pB;
        }
        
        pA = pA->next;
        pB = pB->next;
        
    }
    
    return NULL;
    
}

//Reverse Linked List（反转链表）
//LeetCode 206
ListNode* reverseList(ListNode *head){
    
    ListNode *pre = NULL;
    ListNode *cur = head;
    
    while (cur != NULL) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

//Merge Two Linked List（合并两个有序链表）
//LeetCode 21
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    ListNode *mergedNode = NULL;
    if (l1->val < l2->val) {
        mergedNode = l1;
        mergedNode->next = mergeTwoLists(l1->next,l2);
    }else{
        mergedNode = l2;
        mergedNode->next = mergeTwoLists(l1,l2->next);
    }
    return mergedNode;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    ListNode *mergedNode = new ListNode(-1);
    //ListNode p(-1);
    ListNode *cur = mergedNode;
    while (l1!=NULL&&l2!=NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1= l1->next;
        }else{
            cur->next = l2;
            l2= l2->next;
        }
        cur = cur->next;
    }
    if (l1) {
        cur->next = l1;
    }
    if (l2) {
        cur->next = l2;
    }
    
    cur = mergedNode->next;
    delete mergedNode;
    return cur;
}
