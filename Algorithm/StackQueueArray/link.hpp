//
//  link.hpp
//  Algorithm
//
//  Created by marco on 2019/3/25.
//  Copyright © 2019 flywire. All rights reserved.
//

#ifndef link_hpp
#define link_hpp


#include <stdio.h>
#include <set>
#include <map>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

struct RandomListNode {
    int val;
    RandomListNode *next,*random;
    RandomListNode(int x):val(x),next(NULL),random(NULL){}
};

class Solution{
public:
    ListNode *reverseList(ListNode* head);
    ListNode *reverseBetween(ListNode* head,int m,int n);
    ListNode *getIntersectionNode(ListNode* headA,ListNode* headB);
    ListNode *detectCycle(ListNode* head);
    ListNode *detectCycle2(ListNode* head);
    ListNode *partition(ListNode* head,int x);

    RandomListNode *copyRamdomList(RandomListNode* head);

    ListNode *mergeTwoList(ListNode* L1,ListNode* L2);
    ListNode *mergeKList(std::vector<ListNode*>& lists);

};

#endif /* link_hpp */
