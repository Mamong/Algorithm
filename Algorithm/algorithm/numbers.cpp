//
//  numbers.cpp
//  Algorithm
//
//  Created by marco on 2019/8/19.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "numbers.hpp"
#include "common.hpp"

void Numbers::test()
{
    
}


int max(int a,int b){
    int temp = 0;
    if (a<b) {
        swap(a,b);
    }
    while (b != 0) {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
