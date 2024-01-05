//
//  seq_search.cpp
//  Algorithm
//
//  Created by marco on 2019/3/18.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "seq_search.hpp"


/*
顺序查找，也叫线性查找。哨兵避免不必要的判断
 查找第i个元素，需要进行n-i+1次比较，平均查找长度ASL是对其区间[1,n]求和，当每个元素查找概率相等时，即Pi=1/n,
 ASL=(n+1)/2
 */

typedef struct {
    int *elem;
    int TableLen;
} SSTable,SSList;

int search_seq(SSTable ST,int key){
    ST.elem[0] = key;
    for (int i = ST.TableLen; ST.elem[i]!=key; i--);
    return key;
}

/*
 有序顺序表的折半查找，二分查找
 */
int Binary_Search(SSList L,int key){
    int low = 0,high = L.TableLen-1,mid;
    while (low<=high) {
        mid = (low+high)/2;
        if (L.elem[mid]==key) {
            return mid;
        }else if (L.elem[mid]>key){
            high = mid-1;
        }else
            low = mid+1;
    }
    return -1;
}

/*
 分块查找
 */
