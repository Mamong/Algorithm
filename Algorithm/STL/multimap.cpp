//
//  multimap.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "multimap.hpp"
#include <map>
#include <string>
#include <iostream>
using namespace std;

/*
 multimap容器，与map容器的唯一区别是：multimap支持多个相同键值。
 
 由于支持多个相同键值，multimap提供了cout函数来计算同一个key的元素个数。
 
 */


void MultimapDemo::test(){
    multimap<int, string> map2;
    map2.insert(make_pair(1, "sales"));
    map2.insert(make_pair(1, "develop"));
    map2.insert(make_pair(1, "final"));
    map2.insert(make_pair(2, "part"));

    int oneCount = (int)map2.count(1);
    
    multimap<int, string>::iterator it2 = map2.find(1);
    int tag = 0;
    while (it2 != map2.end() && tag < oneCount) {
        cout << it2->first << "\t" << it2->second <<endl;
        it2 ++;
        tag ++;
    }
}
