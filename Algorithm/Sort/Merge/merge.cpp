//
//  merge.c
//  Algorithm
//
//  Created by marco on 2019/2/10.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "merge.hpp"
#include <cstdlib>

//归并排序包括二路归并排序
//归并的含义就是两个或两个以上的有序表合并成一个新的有序表。
//假定排序表含有n个元素，则可以看作n个有序子表，每个子表长度为1，然后两两归并，得到[n/2]个长度为2或者1的有序表；再进行两两归并...如此重复，直到合并成一个长度为n的有序表为止，这种排序方法称为二路归并排序。
//递归形式的2路归并算法是分治法的应用。
//分解：将n个元素分成各含n/2个元素的子序列。
//解决：用归并排序对两个子序列递归地排序。
//合并：合并两个已排好序的子序列可得到排序结果。
//平均时间复杂度为O(nlog2n)，占用n个辅助空间，每一趟就释放，空间复杂度为O(n)。是一种稳定的排序方法。
//一般而言，对于N个元素进行k路归并排序时，排序的趟数m满足k**m=N，从而m=logkN，又考虑到m为整数，所以m=[logkN]。
void merge(int list[], int left,int mid, int right);

void mergeSort(int list[], int left, int right){
    if (left < right) {
        int mid = (left+right)/2;//从中间划分两个子序列
        mergeSort(list,left,mid);//对左侧子序列进行递归排序
        mergeSort(list,mid+1,right);//对右侧子序列进行递归排序
        merge(list,left,mid,right);//归并
    }
}

int *bList = (int*)malloc((right-left+1)*sizeof(int));


void merge(int list[], int left,int mid, int right){
    int i,j,k;
    //int *bList = (int*)malloc((right-left+1)*sizeof(int));
    //表list的两段list[left...mid]和list[mid+1...right]各自有序，将它们合并成一个有序表
    //将list中所有元素复制到bList中
    for (k = left; k<= right; k++) {
        bList[k] = list[k];
    }
    //i,j,k分别指向第一个表，第二个表和list。
    for (i=left,j=mid+1,k=i; i<=mid&&j<=right; k++) {
        //比较blist的左右两段元素
        //复制较小值到list
        if (bList[i]<bList[j]) {
            list[k]=bList[i++];
        }else{
            list[k]=bList[j++];
        }
    }
    //若第一个表未检测完，复制
    while (i<=mid) {
        list[k++]=bList[i++];
    }
    //若第二个表未检测完，复制
    while (j<=right) {
        list[k++]=bList[j++];
    }
//    free(bList);
}
