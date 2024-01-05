//
//  algorithm.cpp
//  Algorithm
//
//  Created by marco on 2019/8/18.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "algorithm.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void AlgorithmDemo::test()
{
    vector<int> nums = {4,5,1,2,3};
    //heap sort
    /*
     
     make_heap(_RAIter,_RAIter) 默认生成大顶堆
     make_heap(_RAIter,_RAIter,_Compare) _Compare有两种参数，一种是greater（生成小顶堆），一种是less（生成大顶堆）

     */
    make_heap(nums.begin(),nums.end());
    cout << "initial max value : " << nums.front() << endl;
    
    //pop_heap()是在堆的基础上，弹出堆顶元素。将front放在end前部，剩下的元素构成新的heap。
    /*
     pop_heap(_RAIter,_RAIter) 默认为大顶堆
     pop_heap(_RAIter,_RAIter,_Compare) _Compare有两种参数，一种是greater（小顶堆），一种是less（大顶堆）
     比如pop_heap(nums.begin(), nums.end(),greater<int>())，
     它会将堆顶元素（即为数组第一个位置）和数组最后一个位置对调，然后你可以调用数组pop_back，删除这个元素
     注意，pop_heap中的_Compare和make_heap中的_Compare参数必须是一致的，不然会失败
     ————————————————
     版权声明：本文为CSDN博主「wsx_iot」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
     原文链接：https://blog.csdn.net/qq_29630271/article/details/66478256
     
     */
    pop_heap(nums.begin(),nums.end());
    nums.pop_back();
    cout << "after pop, the max vsalue : " << nums.front() << endl;
    
    // push a new value
    nums.push_back(0);
    //push_heap()是将数组最后一个元素插入堆中，并且使堆的规则依然成立
    /*
     push_heap(_RAIter,_RAIter) 默认为大顶堆
     push_heap(_RAIter,_RAIter,_Compare) _Compare有两种参数，一种是greater（小顶堆），一种是less（大顶堆）
     调用push_heap之前必须调用make_heap创建一个堆
     首先数组push_back插入元素，然后再调用push_heap，它会使最后一个元素插到合适位置
注意，push_heap中的_Compare和make_heap中的_Compare参数必须是一致的，不然会插入堆失败，最后一个元素还是在最后位置，导致插入失败
     */
    push_heap(nums.begin(), nums.end());
    cout << "after push, the max value : " << nums.front() << endl;
    
    //堆排序
    sort_heap(nums.begin(), nums.end());
}
