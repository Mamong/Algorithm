//
//  set.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "set.hpp"
#include <set>
#include <iostream>
using namespace std;


/*
 
 set是一个集合，Objective-C语言中也有集合的概念。C++中的集合与OC中的集合也有不同的地方。
 
 C++的set容器，其中包含的元素是唯一的，而且是有序的。
 C++的set容器，是按照顺序插入的，不能在指定位置插入。
 C++的set容器，其结构是红黑二叉树，插入数据的效率比vector快
 
 set容器是有序的集合，默认的顺序是从小到大的。
 创建集合的方式：
 
 set<int>创建默认的从小到大的int类型的集合
 
 set<int,less<int>>创建一个从小打到大的int类型的集合
 
 set<int,greater<int>>创建一个从大到小的int类型的集合
 
 上面的less和greater就是仿函数，集合会根据这个仿函数的返回值是否为真类进行排序。
 
 //仿函数的原型，下面是C++提供的默认的greater的仿函数(删除了宏定义后的)
 struct greater
 {
 bool operator()(const int &left, const int &right) const
 {
 //如果左值>右值，为真。从大到小的排列
 return left > right;
 }
 };
 
 */

void SetDemo::test(){
    
    set<int> set1;
    
    //插入元素
    for (int i = 0; i<5; i++) {
        int tmp = rand();
        set1.insert(tmp);
    }
    
    //重复插入元素（会插入不成功，下一节会分析如果根据返回值判断是否插入成功）
    set1.insert(100);
    set1.insert(100);
    set1.insert(100);
    pair< set<int>::iterator,bool> result = set1.insert(100);
    if (result.second) {
        cout << "插入s1成功" <<endl;
    }else{
        cout << "插入s1失败" <<endl;
    }
    
    for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        cout << *it <<" ";
    }
    
    //删除集合
    while(!set1.empty())
    {
        //获取头部
        set<int>::iterator it = set1.begin();
        
        //打印头部元素
        cout << *it << endl;
        
        //从头部删除元素
        set1.erase(set1.begin());
    }
    
}


//我们可以测试下，添加进set集合的元素确实是有顺的。
void SetDemo::test2(){
    
    //默认，从小到大
    set<int> set1;
    //从小到大--默认就是
    set<int, less<int>> set2;
    //从大到小
    set<int, greater<int>> set3;
    
    //添加元素
    for (int i = 0; i < 5; i++) {
        int tmp = rand();
        set3.insert(tmp);
    }
    
    //遍历
    for (set<int>::iterator it = set3.begin(); it != set3.end(); it++) {
        cout<< *it << " ";
    }
}

//set容器数据的查找
/*
 set容器提供了多个函数用来查找元素
 
 
 iterator find(const key_type& __k) find函数查找元素为k的迭代器位置
 
 iterator lower_bound(const key_type& __k) lower_bound函数查找小于等于元素k的迭代器位置
 
 iterator upper_bound(const key_type& __k) upper_bound函数查找大于元素k的迭代器位置
 
 pair<iterator,iterator> equal_range(const key_type& __k) equal_range函数返回一个pair类型，第一个属性表示大于等于k的迭代器位置，第二个是大于k的迭代器位置
 
 */
void SetDemo::test3(){
    set<int> set1;
    
    for (int i = 0; i < 10; i++) {
        set1.insert(i+1);
    }
    
    
    //遍历
    for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        cout << *it <<endl;
    }
    
    //查找元素是5的迭代器位置
    set<int>::iterator it0 = set1.find(5);
    cout << "it0:" << *it0 <<endl;
    
    //查找小于等于5的元素迭代器位置
    set<int>::iterator it1 = set1.lower_bound(5);
    cout << "it1:" << *it1 <<endl;
    
    //查找大于5的元素迭代器位置
    set<int>::iterator it2 = set1.upper_bound(5);
    cout << "it2:" << *it2 <<endl;
    
    //返回的pair第一个迭代器是=5的第一个位置,另一个是>5的第一个位置
    pair<set<int>::iterator, set<int>::iterator> mypair = set1.equal_range(5);
    set<int>::iterator it3 = mypair.first;
    set<int>::iterator it4 = mypair.second;
    cout << "it3:" << *it3 <<endl;
    cout << "it4:" << *it4 <<endl;
}
