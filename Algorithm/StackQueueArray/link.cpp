//
//  link.cpp
//  Algorithm
//
//  Created by marco on 2019/3/25.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "link.hpp"


ListNode * Solution::reverseList(ListNode* head){
    ListNode *new_head = NULL,*node = NULL;
    while (head) {
        node = head->next;
        head->next = new_head;
        new_head=head;
        head = node;
    }
    return new_head;
}

//1<=m<=n<=链表长度
ListNode * Solution::reverseBetween(ListNode* head,int m,int n){
    int change_len = n - m + 1;
    ListNode *pre_head = NULL,*result = head;
    while (head && --m) {
        pre_head = head;
        head = head->next;
    }
    ListNode *modify_list_tail = head;
    ListNode *new_head = NULL;
    while (head && change_len--) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    modify_list_tail->next = head;
    if (pre_head) {
        pre_head->next = new_head;
    }else{
        result = new_head;
    }
    return result;
}

//还有一种办法是长的前移m-n位，跟短的一样长的时候，一起向前移，直到两个结点相同
ListNode* Solution::getIntersectionNode(ListNode* headA,ListNode* headB)
{
    std::set<ListNode*> node_set;
    while (headA) {
        node_set.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (node_set.find(headB) != node_set.end()) {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

//环检测
ListNode* Solution::detectCycle(ListNode* head)
{
    std::set<ListNode*> node_set;
    while (head) {
        if (node_set.find(head) != node_set.end()) {
            return head;
        }
        node_set.insert(head);
        head = head->next;
    }
    return NULL;
}

ListNode* Solution::detectCycle2(ListNode* head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *meet = NULL;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
        if (!fast) {
            return NULL;
        }
        fast = fast->next;
        if (fast==slow) {
            meet = fast;
            break;
        }
    }
    if (meet == NULL) {
        return NULL;
    }
    while (head&&meet) {
        if (head == meet) {
            return head;
        }
        head = head->next;
        meet = meet->next;
    }
    
    return NULL;
}

ListNode* Solution::partition(ListNode* head,int x)
{
    ListNode less_node(0);
    ListNode more_node(0);
    ListNode *less_ptr = &less_node;
    ListNode *more_ptr = &more_node;
    while (head) {
        if (head->val<x) {
            less_node.next = head;
            less_ptr = head;
        }else{
            more_node.next = head;
            more_ptr = head;
        }
        head = head->next;
    }
    less_ptr->next = more_node.next;
    more_ptr->next = NULL;
    return less_node.next;
}

RandomListNode* Solution::copyRamdomList(RandomListNode* head)
{
    std::map<RandomListNode*, int> node_map;
    std::vector<RandomListNode*> node_vec;
    RandomListNode *ptr = head;
    int i = 0;
    while (ptr) {
        node_vec.push_back(new RandomListNode(ptr->val));
        node_map[ptr] = i;
        ptr = ptr->next;
        i++;
    }
    node_vec.push_back(0);
    ptr = head;
    i = 0;
    while (ptr) {
        node_vec[i]->next = node_vec[i+1];
        if (ptr->random) {
            int id = node_map[ptr->random];
            node_vec[i]->random = node_vec[id];
        }
        ptr = ptr->next;
        i++;
    }
    return node_vec[0];
}

//21. 两个有序列表的合并
ListNode* Solution::mergeTwoList(ListNode* L1,ListNode* L2)
{
    ListNode temp_head(0);
    ListNode *pre = &temp_head;
    while (L1 && L2) {
        if (L1->val < L2->val) {
            pre->next = L1;
            L1= L1->next;
        }else{
            pre->next = L2;
            L2= L2->next;
        }
        pre = pre->next;
    }
    if (L1) {
        pre->next = L1;
    }
    if (L2) {
        pre->next = L2;
    }
    return temp_head.next;
}

//23. k个有序列表的合并
//合并排序再相连
//两两合并
ListNode* Solution::mergeKList(std::vector<ListNode*>& lists)
{
    if (lists.size() == 0) {
        return 0;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    if (lists.size() == 2) {
        return mergeTwoList(lists[0], lists[1]);
    }
    int mid = lists.size()/2;
    
    std::vector<ListNode*> sub1_lists;
    std::vector<ListNode*> sub2_lists;

    for (int i = 0; i<mid; i++) {
        sub1_lists.push_back(lists[i]);
    }
    for (int i = mid; i <lists.size(); i++) {
        sub2_lists.push_back(lists[i]);
    }
    
    ListNode *l1 = mergeKList(sub1_lists);
    ListNode *l2 = mergeKList(sub2_lists);
    return mergeTwoList(l1,l2);
}
