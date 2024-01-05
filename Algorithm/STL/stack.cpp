//
//  stack.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "stack.hpp"
#include <stack>
#include <iostream>
using namespace std;

/*
 push
 pop
 size
 empty->bool
 top
 
 emplace:以vector为例，vStr.push_back(MyString("can ge ge blog")) 这个语句首先执行了构造函数，构造一个临时对象，接着执行拷贝构造将临时对象复制到vector，最后销毁临时对象和vector中的元素。而emplace_back只调用一次构造函数和一次析构函数。两相对比，效率上的提高不言而喻
 swap
 */

void StackDemo::test(){
    stack<int> s1;
    
    s1.push(1);
    s1.push(2);
    s1.pop();

    while (!s1.empty()) {
        //取出栈顶元素
        cout << "当前栈顶元素" << s1.top() << endl;
        
        //获取栈的大小
        cout << "当前栈的大小" << s1.size() << endl;
        
        //出栈
        s1.pop();
    }
    
}
