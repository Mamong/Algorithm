//
//  list.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "list.hpp"
#include <list>
#include <iostream>
using namespace std;


//list是一个双向链表,可以直接在头尾插入和删除
//不能随机访问，迭代器只能++，和deque类似，除了不能随机访问
void ListDemo::test(){
    
    list<int> l;
    
    //尾部添加元素
    for (int i = 0; i < 10; i++) {
        l.push_back(i);
    }
    
    //头部添加元素
    l.push_front(111);
    
    l.pop_back();
    l.pop_front();
    
    
    
    //遍历
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    //list不能随机访问
    list<int>::iterator it = l.begin();
    it++;
    it++;
    cout << *it <<endl;
//        it = it + 1;  //编译报错，不能随机访问
    //    it = it + 5;  //编译报错，不能随机访问
    
    
    
    //删除头部元素
    l.erase(l.begin());
    
    //删除某个区间
    list<int>::iterator it2 = l.begin();
    it2++;
    it2++;
    it2++;
    l.erase(l.begin(), it);
    
    //移除值为100的所有元素
    l.remove(100);
    
    //遍历
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
