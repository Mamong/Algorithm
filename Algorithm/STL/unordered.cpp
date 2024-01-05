//
//  unordered.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "unordered.hpp"
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
/*
 
 
 在C++11中有新出4个关联式容器：unordered_map/unordered_set/unordered_multimap/unordered_multiset。
 
 这4个关联式容器与map/multimap/set/multiset功能基本类似，最主要就是底层结构不同，使用场景不容。
 
 如果需要得到一个有序序列，使用红黑树系列的关联式容器；如果需要更高的查询效率，使用以哈希表为底层的关联式容器。
 map,set,multimap,multiset上述四种容器采用红黑树实现
 
 
 C++ unordered_map及其基本结构和特性
 http://c.biancheng.net/view/526.html
 
 
 STL中的map和unordered_map选择
 https://blog.csdn.net/hnlylyb/article/details/81189236
 */


void UnorderedDemo::test(){
    
    unordered_map<int,string> unmap;
    unmap.insert(make_pair(1, "ok"));
    unmap.insert(make_pair(2, "apple"));
    
    string value = unmap[1];
    cout << value;
    
}
