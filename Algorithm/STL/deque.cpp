//
//  deque.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "deque.hpp"
#include <deque>
using namespace std;

//双端队列，可以在头部尾部插入删除元素

void DequeDemo::test(){
    
    deque<int> d1;
    
    d1.push_back(10);
    d1.push_front(10);
    d1.pop_back();
    d1.pop_front();
    
    d1.front() = 5;
    d1.back() = 6;
    
    //双端队列可以随机访问
    d1[0] = 1;
    
    long distance = std::distance(d1.begin(), d1.begin()+1);
}
