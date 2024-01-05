//
//  queue.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "queue.hpp"
#include <queue>
#include <iostream>
using namespace std;


void QueueDemo::test(){
    
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "对头元素" << q.front() <<endl;
    cout << "对尾元素" << q.back() <<endl;
    cout << "队列的大小 " << q.size() <<endl;
    

    while (!q.empty()){
        int tmp = q.front();
        int back = q.back();
        cout << tmp << " "<<back;
        q.pop();
    }
}
