//
//  main.m
//  Algorithm
//
//  Created by marco on 2019/2/10.
//  Copyright © 2019 flywire. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "exchange.hpp"

#include<iostream>
#include "common.hpp"
#include "excise.hpp"

#import "link.hpp"

using namespace  std;


void sortTest(){
    //int list[] = {10,7,9,4,6,8,3,5,2,1};
    //int list[] = {7,7,7,7,7,7,7,7,7,7};
    //int list[] = {1,2,3,4,5,6,7,8,9,10};
    int list[]={1,4,9,3,8,98,34,2,87};

    //bubbleSort1(list, 10);
    //quickSort(list, 0, 9);
    quickSort(list, 0, 8);

    for (int j=0;j<9;++j){
        cout<<list[j]<<" ";
    }
    cout<<endl;
}

void listTest(){
    LinkList list;
    creatList2(list);
    linkDelete(list, 10);
    printList2(list);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        //listTest();
        
        /*ListNode a(1);
        ListNode b(2);
        ListNode c(3);
        ListNode d(4);
        ListNode e(5);
        
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = &e;
        
        Solution solve;
        ListNode *head = &a;
        printf("before reverse:\n");
        while (head) {
            printf("%d\n",head->val);
            head = head->next;
        }
        //head = solve.reverseList(&a);
        head = solve.reverseBetween(&a, 1, 4);
        printf("after reverse:\n");
        while (head) {
            printf("%d\n",head->val);
            head = head->next;
        }*/
        
        //int list[]={8,8,7,8,4,9,3,8,98,34,2,87};
        int list[]={18,38,7,58,4,9,3,8,98,34,2,87};

        Excise ex;
        ex.quickSort(list, 0, 11);
        printf("ok");
        //sortTest();
    }
    return 0;
}
