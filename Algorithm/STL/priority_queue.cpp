//
//  priority_queue.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "priority_queue.hpp"
#include <queue>
#include <iostream>
using namespace std;


/*
 
 优先级队列容器
 
 定义：priority_queue<Type, Container, Functional>
 Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式。
 
 
 优先级队列分为：最小值优先队列和最大值优先队列。
 此处的最大值、最小值是指队头的元素（增序、降序）。默认，是创建最大值优先级队列。
 定义优先级的方法：
 
 
 priority_queue<int>默认定义int类型的最大值队列
 
 priority_queue<int, vector<int>, less<int>>定义int型的最大值优先队列
 
 priority_queue<int, vector<int>, greater<int>>定义int型的最小值队列
 
 上面的定义中，less和greater相当于谓词，是预定义好的排序函数，我们称之为“仿函数”。
 
 作者：一月二十三
 链接：https://www.jianshu.com/p/497843e403b4
 来源：简书
 简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
 
 https://www.cnblogs.com/huashanqingzhu/p/11040390.html
 
 
 
 和队列基本操作相同:
 
 top 访问队头元素
 empty 队列是否为空
 size 返回队列内元素个数
 push 插入元素到队尾 (并排序)
 emplace 原地构造一个元素并插入队列

 pop 弹出队头元素
 swap 交换内容
 
 */

void PriorityQDemo::test(){
    //默认大顶堆
    priority_queue<int> p1;
    priority_queue<int, vector<int>, less<int>> p2;
    priority_queue<int, vector<int>, greater<int>> p3;

    
    //加入元素
    p1.push(33);
    p1.push(11);
    p1.push(55);
    p1.push(22);
    
    //删除堆顶元素
    p1.pop();
    
    //打印最大优先级的对头元素
    cout<<"队头元素:"<< p1.top() <<endl;
    cout<<"队列的大小:"<< p1.size() <<endl;
    
    //给最小值优先级队列入栈
    p3.push(33);
    p3.push(11);
    p3.push(55);
    p3.push(22);
    
    //打印最小优先级队列的对头元素
    cout<<"对头元素:"<< p3.top() <<endl;
    cout<<"队列的大小:"<< p3.size() <<endl;
}
