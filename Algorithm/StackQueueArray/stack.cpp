//
//  stack.cpp
//  Algorithm
//
//  Created by marco on 2019/3/25.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "stack.hpp"

void MinStack::push(int x)
{
    _data.push(x);
    if (_min.empty()) {
        _min.push(x);
    }else{
        if (x > _min.top()) {
            x = _min.top();
        }
        _min.push(x);
    }
}

void MinStack::pop()
{
    _data.pop();
    _min.pop();
}

int MinStack::top()
{
    return _data.top();
}

int MinStack::getMin()
{
    return _min.top();
}


//poj 1363
bool MinStack::check_is_valid_order(std::queue<int> &order)
{
    std::stack<int> S;
    int n = order.size();
    for (int i = 1; i < n; i++) {
        S.push(i);
        while (!S.empty()&&S.top() == order.front()) {
            S.pop();
            order.pop();
        }
    }
    if (!S.empty()) {
        return false;
    }
    return true;
}
