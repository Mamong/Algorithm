//
//  excise.cpp
//  Algorithm
//
//  Created by marco on 2019/6/28.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "excise.hpp"
#include "common.hpp"
#include <utility>

using namespace std;
/*
//直接插入排序
void directInsertSort(int list[],int n)
{
    int i,j;
    for (i=2; i<=n; i++) {
        if (list[i]<list[i-1]) {
            list[0] = list[i];
            j=i-1;
//            while (list[0]<list[j]) {
//                list[j+1]=list[j];
//                j--;
//            }
            
            for (; list[0]<list[j]; j--) {
                list[j+1]=list[j];
            }
            list[j+1]=list[0];
        }
    }
}

//折半插入
void halfInsertSort(int list[],int n)
{
    int i,j,low,mid,high;
    for (i=2; i<=n; i++) {
        //复制哨兵
        list[0] = list[i];
        low = 1;
        high = i-1;
        while (low<=high) {
            mid = (low+high)/2;
            if (list[mid]>list[0]) {
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
//        for (j=i-1; j>=high+1; j--) {
//            list[j+1]=list[j];
//        }
//        list[high+1]=list[0];
        
        for (j=i-1; j>=low; j--) {
            list[j+1]=list[j];
        }
        list[low]=list[0];
    }
}

//冒泡排序
void bubbleSort(int list[],int n)
{
    int i,j;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j], list[j-1]);
            }
        }
    }
}

void bubbleSort1(int list[],int n)
{
    int i,j;
    bool flag = false;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j], list[j-1]);
                flag = true;
            }
        }
        if (flag) {
            return;
        }
    }
}

void bubbleSort2(int list[],int n)
{
    int i,j;
    int lastSwapTemp=0,lastSwap=0;
    for (i=0; i<n-1; i++) {
        lastSwap = lastSwapTemp;
        for (j=n-1; j>lastSwap; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j], list[j-1]);
                lastSwapTemp = j;
            }
        }
        if (lastSwap == lastSwapTemp) {
            return;
        }
    }
}

//快速排序
int partion(int list[],int left,int right)
{
    int pivot;
    pivot = list[0];
    while (left < right) {
        while (left < right && list[right] >= pivot) {
            right--;
        }
        list[left]=list[right];
        while (left < right && list[left] <= pivot) {
            left++;
        }
        list[right]=list[left];
    }
    list[left]=pivot;
    return left;
}

void quickSort(int list[],int left,int right)
{
    if (left<right) {
        int pivot = partion(list, left, right);
        quickSort(list,left,pivot-1);
        quickSort(list,pivot+1,right);
    }
}

//简单选择排序
void simpleSelectSort(int list[],int n)
{
    int i,j,min = 0;
    //从0开始，比较到n-2个位置，n-1自然确定
    for (i = 0; i< n-1; i++) {
        min = i;
        //从i+1比较到n-1
        for (j = i+1; j< n; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if(min!=i)swap(list[min], list[i]);
    }
}

void buildMaxHeap(int A[], int len);
void adjustDown(int A[],int k,int len);


void heapSort(int A[],int len){
    buildMaxHeap(A,len);
    for (int i=len; i>1; i--) {
        swap(A[1], A[i]);
        adjustDown(A,1,i-1);
    }
}

void buildMaxHeap(int A[], int len){
    for (int i = len/2; i > 0; i--) {
        adjustDown(A, i, len);
    }
}

void adjustDown(int A[],int k,int len){
    A[0]=A[k];
    for (int i = 2*k; i<= len; i*=2) {
        //i指向左右孩子较大者下标
        if (i<len && A[i]<A[i+1]) {
            i = i+1;
        }
        //当前节点比左右孩子都大
        if (A[0]>=A[i]) {
            break;
        }else{
            //将较大子节点调整到双亲结点
            A[k] = A[i];
            //记录较大节点位置
            k = i;
        }
    }
    A[k] = A[0];
}
*/

void printList(int list[],int from,int to){
    for (int i = from; i <=to; i++) {
        printf("-%d-",list[i]);
    }
}


int partion(int list[],int left,int right);

//快排
void Excise::quickSort(int list[],int left,int right)
{
    if (left < right) {
        int pivot = partion(list,left,right);
        quickSort(list, left, pivot-1);
        quickSort(list, pivot+1, right);
    }
}

//必须把pivot的位置先空出来，最后交换到合适的位置
//如果一开始就参与交换，最后位置不正确，可能在靠后的位置发现一个比pivot小的数，
//然后刚好和pivot交换，导致pivot在靠后的位置，尽管l的值才是正确的pivot的下标
int partion(int list[],int left,int right){
    int l = left;      //l指向比pivot小的最大下标
    int i = left;
    int pivot = list[left];

    while (i <= right) {
        if (list[i]<pivot) {
            swap(list[++l], list[i]);
        }
        i++;
    }
    //把pivot放到l处，把l处比pivot小的放到left
    swap(list[left], list[l]);
    return l;
}



//两路快排
int partion2(int list[],int left,int right);

 void Excise::quickSort2(int list[],int left,int right)
 {
     if (left < right) {
         int pivot = partion2(list,left,right);
         quickSort2(list, left, pivot-1);
         quickSort2(list, pivot+1, right);
     }
 }
 
int partion2(int list[],int left,int right){
    int pivot = list[left];
    while (left < right) {
        while (left < right && list[right]>=pivot) {
            right--;
        }
        list[left]=list[right];
        while (left < right && list[left]<=pivot) {
            left++;
        }
        list[right]=list[left];
    }
    list[left]=pivot;
    printf("-%d-",left);
    return left;
}


//三路快排
pair<int, int> partion3(int list[],int left,int right);

/*
void Excise::quickSort(int list[],int left,int right)
{
    if (left < right) {
        pair<int, int> pair = tpartion(list,left,right);
        quickSort(list, left, pair.first-1);
        quickSort(list, pair.second+1, right);
    }
}

pair<int, int> tpartion(int list[],int l,int r){

    int lt = l;        // 循环过程中保持 arr[l+1...lt] < v
    int gt = r+1;        // 循环过程中保持 arr[gt...r] > v
    int i = l+1;       // 循环过程中保持 arr[lt+1...i) == v
    int v = list[l];   // v为pivot，初始存储在arr[l]的位置

    while( i < gt ){
        if( list[i] < v ){
            swap(list[i++], list[++lt]);
        }
        else if( list[i] > v ){
            swap(list[i], list[--gt]);
        }
        else
            i++;
    }
    //list[l]==pivot.list[lt]<pivot，因此需要交换它们
    //此时[l...it-1]<pivot,[it...gt-1]=pivot,[gt...r]>pivot
    swap(list[l],list[lt]);
    return make_pair(lt,gt-1);
}*/

void Excise::quickSort3(int list[],int left,int right)
{
    if (left < right) {
        pair<int, int> pair = partion3(list,left,right);
        quickSort3(list, left, pair.first);
        quickSort3(list, pair.second, right);
    }
}

//pivot一开始就参与交换，只会被交换到和pivot值一样的区间
pair<int, int> partion3(int list[],int l,int r){
    
    int lt = l;        // 循环过程中保持 arr[l...lt] < v
    int gt = r+1;      // 循环过程中保持 arr[gt...r] > v
    int i = l;         // 循环过程中保持 arr[lt+1...i) == v
    int v = list[l];   // v为pivot，初始存储在arr[l]的位置
    
    while( i < gt ){
        if( list[i] < v ){
            swap(list[i++], list[lt++]);
        }
        else if( list[i] > v ){
            swap(list[i], list[--gt]);
        }
        else
            i++;
    }
    //此时[l...it]<pivot,[it+1...gt-1]=pivot,[gt...r]>pivot
    return make_pair(lt,gt);
}
