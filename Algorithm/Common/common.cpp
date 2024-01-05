//
//  common.cpp
//  Algorithm
//
//  Created by marco on 2019/2/11.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "common.hpp"
#include <stdlib.h>



//头插法：逆序
LinkList creatList1(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;int x;
    scanf("%d",&x);
    while (x!=9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->value = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法：顺序
LinkList creatList2(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s,*r=L;int x;
    scanf("%d",&x);
    while (x!=9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->value = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

//不带头结点
void printList(LinkList L){
    LNode *p = L;
    while (p) {
        printf("%d\n",p->value);
        p = p->next;
    }
}

//带头结点的打印
void printList2(LinkList L){
    LNode *p = L->next;
    while (p) {
        printf("%d\n",p->value);
        p = p->next;
    }
}


void linkDelete(LinkList &L,int d){
    LNode *p;
    if (L==NULL) {
        return;
    }
    if (L->value == d) {
        p=L;
        L=L->next;
        free(p);
        linkDelete(L,d);
    }else{
        linkDelete(L->next,d);
    }
}
