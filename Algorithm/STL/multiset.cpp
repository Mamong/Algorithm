//
//  mutliset.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "multiset.hpp"
#include <set>
#include <iostream>
using namespace std;

/*
 multiset容器，与set容器相似，但是multiset容器中的元素可以重复。另外，他也是自动排序的，容器内部的值不能随便修改，因为有顺序的。
 
 */


void MutlisetDemo::test(){
    //定义multiset
    multiset<int> set1;
    
    //从键盘不停的接收值
    int tmp = 0;
    printf("请输入multiset集合的值:");
    scanf("%d", &tmp);
    while (tmp != 0) {
        set1.insert(tmp);
        scanf("%d", &tmp);
    }
    
    //迭代器遍历
    for (multiset<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        cout<< *it <<" ";
    }
    cout <<endl;
    
    //删除
    while (!set1.empty()) {
        multiset<int>::iterator it = set1.begin();
        cout << *it << " ";
        set1.erase(it);
    }
}
