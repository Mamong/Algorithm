//
//  exchange.c
//  Algorithm
//
//  Created by marco on 2019/2/10.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "exchange.hpp"
#include "common.hpp"

//交换排序包括冒泡排序、快速排序。
//交换就是根据两个元素的关键字比较结果来交换这两个元素在序列里位置。

/*从小到大排列
 @param list 待排序序列
 @param n    序列长度
 */

//基本思想：待排序表长n，从后往前(从前往后)两两比较相邻元素的值，若为逆序（即A[i-1]>A[i]),则交换它们，直到序列比较完，称为一趟冒泡，结果将最小的元素交换到序列的第一个位置。
//下一趟冒泡时，前一趟确定的最小元素不再参与比较，待排序列较少一个元素，每趟冒泡的结果是把序列中的最小元素放到了序列的最终位置。
//判断排序结束条件：在一趟排序过程中没有进行元素交换的操作。整个排序过程需要进行k（1<=k<n）趟冒泡排序。
//当初始序列有序时，只需要一趟冒泡后就跳出循环，仅需比较n-1次，无需交换；
//当初始序列无序时，需要冒泡n-1趟，比较1+...+n-1=n(n-1)/2次，移动3n(n-1)/2次。
//冒泡排序时间复杂度O(n2),空间复杂度O(1),是一种稳定的排序方法。
//冒泡排序产生的有序子序列是全局有序的（不同于直接插入排序），这样每一趟排序都会将一个元素放到其最终位置。
//冒泡排序的写法，主要是双层循环，难点在于边界的处理。
//上浮
void bubbleSortUp(int list[], int n){
    //最多冒泡n-1趟
    for(int i = 0;i < n-1; i++){
        //从最后一个元素开始比较，到有序序列之前2个
        for (int j = n-1; j > i; j--) {
            if (list[j-1]>list[j]) {
                swap(list[j-1],list[j]);
            }
        }
    }
}

/*void bubbleSort(int list[],int n){
    int i,j;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j],list[j-1]);
            }
        }
    }
}
void bubbleSorta(int list[],int n){
    int i,j;
    bool flag = true;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j],list[j-1]);
                flag = false;
            }
        }
        if (flag) {
            return;
        }
    }
}
void bubbleSortb(int list[],int n){
    int i,j;
    int lastSwap=0;
    int lastSwapTemp=0;
    
    for (i=0; i<n-1; i++) {
        lastSwap = lastSwapTemp;
        for (j=n-1; j>lastSwap; j--) {
            if (list[j]<list[j-1]) {
                swap(list[j],list[j-1]);
                lastSwapTemp = j;
            }
        }
        if (lastSwap == lastSwapTemp) {
            return;
        }
    }
}*/





//下沉
void bubbleSortDown(int list[], int n){
    //最多冒泡n-1趟
    for(int i = 0;i < n-1; i++){
        //从最后一个元素开始比较，到有序序列之前2个
        for (int j = 0; j < n-1-i; j++) {
            if (list[j+1]<list[j]) {
                swap(list[j+1],list[j]);
            }
        }
    }
}


//冒泡排序的改进版本1
void bubbleSort1(int list[], int n){
    bool flag = false;//本趟冒泡是否发生交换标志
    //最多冒泡n-1趟
    for(int i = 0;i < n-1; i++){
        flag = false;
        //从最后一个元素开始比较，到有序序列之前2个
        for (int j = n-1; j > i; j--) {
            if (list[j-1]>list[j]) {
                swap(list[j-1],list[j]);
                flag = true;
            }
        }
        if (flag==false) {
            return;
        }
    }
}

//冒泡排序的改进版本2
//每次记录最后交换的位置(这里是最后交换的位置之前区间[0,lastSwap)都
//是有序的)，只需要在从最后一个有序元素后一个元素继续循环交换即可
void bubbleSort2(int list[], int n){
    int lastSwap=0;
    int lastSwapTemp=0;
    //最多冒泡n-1趟
    for(int i = 0;i < n-1; i++){
        lastSwap=lastSwapTemp;
        //扩大有序区间
        for (int j = n-1; j > lastSwap; j--) {
            if (list[j-1]>list[j]) {
                swap(list[j-1],list[j]);
                lastSwapTemp = j;
            }
        }
        if (lastSwap==lastSwapTemp) {
            return;
        }
    }
}

//快速排序
//快速排序从冒泡排序基础上改进而来，基于分治思想。快速排序是C.R.A.Hoare于1962年提出的一种划分交换排序。它采用了一种分治的策略，通常称其为分治法(Divide-and-ConquerMethod)。
//分解：在表中任取某个元素pivot作为基准，将数组A[left...right]划分为两个子数组A[left...q-1]和A[q+1...right]，使得A[left...q-1]中的每个元素都小于pivot，[q+1...right]中的每个元素都大于pivot。则pivot放在其最终位置上。
//解决：通过递归调用快速排序，对子数组A[left...q-1]和A[q+1...right]进行上述操作。
//合并：由于两个子数组均是在原地进行排序的，故此时所有元素都放到了其最终位置上。
//快速排序运行效率与划分y是否对称有关，而后者又与具体的划分算法有关。最坏的情况发生在两个区域分别包含n-1个和0个元素时，这种对大程度的不对称性若发生在每一层递归上，就得到时间复杂度O(n2)，因此快速排序在最坏情况下并不比插入排序好。此外，当输入数组已经基本有序时，快速排序的运行时间也为O(n2)。
//有很多方法可以提高算法效率。一种是当递归过程中划分得到的子序列规模比较小时，不要再继续递归调用快速排序，可以采用直接插入排序进行后续的排序工作。另一种是尽量选取一个可以将数据中分的基准元素，如从序列的头尾以及中间选区三个元素，再取这三个元素的中间值作为最终的基准元素，这样做使得最坏情况在实际排序中几乎不会发生。
//在理想情况下，也即qPartition做到最平衡的划分，得到两个子序列的大小都不大于n/2，在这种情况下，运行速度大大提升，此时，时间复杂度为O(nlog2n)。快速排序的平均情况运行时间与最佳情况运行时间接近，而不是接近于其最坏情况运行时间。
//由于快排是递归的，需要借助一个栈来存放每一层递归调用的必要信息，其最大容量与递归调用的深度一致。最好的情况下为O(log2n)；最坏的情况下需要进行n-1次递归，栈的深度为O(n)。平均情况下，栈的深度为O（log2n）。快速排序是一种不稳定的排序方法。
int qPartition(int list[],int left, int right);

void quickSort(int list[],int left, int right){
    //递归跳出条件
    if (left < right) {
        //划分列表
        int q = qPartition(list,left,right);
        //依次对两个子列表进行递归排序
        quickSort(list, left, q-1);
        quickSort(list, q+1, right);
    }
}

int qPartition(int list[],int left, int right){
    //以第一个元素为基准将序列划分开，左侧均不大于它，右侧均不小于它
    //pivot暂存，空出第一个位置
    int pivot = list[left];
    while (left < right) {
        while (left<right && list[right]>=pivot) {
            right--;
        }
        //将比基准值小的元素移动到左端
        list[left]=list[right];
        while (left<right && list[left]<=pivot) {
            left++;
        }
        //将比基准值大的元素移动到右端
        list[right]=list[left];
    }
    //left和right重合时，即是基准值最终的位置，并返回这个位置
    list[left]=pivot;
    return left;
}

/*
void quickSorta(int list[],int left,int right){
    if (left < right) {
        int q = qPartitiona(list,left,right);
        quickSorta(list, left, q-1);
        quickSorta(list, q+1, right);
    }
}

int qPartitiona(int list[],int left,int right){
    
    int pivot = list[left];
    while (left<right) {
        while (left < right && list[right] >= pivot) {
            right--;
        }
        list[left] = list[right];
        while (left<right && list[left] >= pivot) {
            left++;
        }
        list[right] = list[left];
    }
    list[left] = pivot;
    return left;
}
*/
