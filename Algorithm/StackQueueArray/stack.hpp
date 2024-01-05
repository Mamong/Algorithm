//
//  stack.hpp
//  Algorithm
//
//  Created by marco on 2019/3/25.
//  Copyright © 2019 flywire. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stack>
#include <queue>

class MinStack {
public:
    MinStack(){}
    void push(int x);
    void pop();
    int top();
    int getMin();
    
    bool check_is_valid_order(std::queue<int> &order);

private:
    std::stack<int> _data;
    std::stack<int> _min;
};

#endif /* stack_hpp */
