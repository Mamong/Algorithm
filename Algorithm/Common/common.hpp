//
//  common.hpp
//  Algorithm
//
//  Created by marco on 2019/2/11.
//  Copyright © 2019 flywire. All rights reserved.
//

#ifndef common_hpp
#define common_hpp

#include <stdio.h>

inline void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

typedef struct LNode {
    int value;
    struct LNode *next,*prior;
} LNode,*LinkList;

LinkList creatList1(LinkList &L);
LinkList creatList2(LinkList &L);
void printList(LinkList L);
void printList2(LinkList L);
void linkDelete(LinkList &L,int d);

#endif /* common_hpp */
