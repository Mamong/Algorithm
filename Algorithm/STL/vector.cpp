//
//  vector.cpp
//  Algorithm
//
//  Created by marco on 2019/7/22.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "vector.hpp"
#include <iostream>
#include <vector>

using namespace std;

void VectorDemo::test(){
    //vector定义
    //空向量
    vector<int> vec;

    //多个重复分量
    vector<int> vec1(4,1); //{1,1,1,1}

    //从数组初始化
    vector<int> vec2{1,2,3,4}; //{1,2,3,4}

    //从另一个向量初始化
    vector<int> vec3(vec1);
    vector<int> vec31 = vec3;

    //从部分数组初始化
    int arr[5] = {1,2,3,4,5};
    vector<int> vec4(arr,arr+5); //{1,2,3,4,5}
    vector<int> vec5(&arr[0],&arr[5]); //{1,2,3,4,5}

    //从部分向量初始化
    vector<int> vec6(vec4.begin(), vec4.begin() + 1);
    vector<int> vec7(vec4.begin(), vec4.end());


    //向量插入元素
    //末尾插入
    vec.push_back(10);
    
    //第一个元素前插入5
    vec.insert(vec.begin(), 5);
    //第二个元素前插入2个5
    vec.insert(vec.begin()+1, 2, 5);

    //内容设置为2个5
    vec.assign(2, 5);
    
    //扩容并填充，size是实际元素的数目，capacity是开辟的容量
    vec.resize(20, 0);
    vec.size();
    vec.capacity();
    
//reserve用来（预留空间，）改变capacity，不改变size，会去分配内存，但不会构造出对象；如果改变后的capacity比当前capacity大，则capacity会变大；反之，capacity不变。reserve是容器预留空间，但并不是真正创建元素。在创建对象前，不能引用容器中的元素，当插入元素时，需要用push_back()和insert()。
//resize用来改变vector的size，有可能也会改变capacity。如果改变后的size比当前capacity大，则capacity会变大，同时构造出多出来的对象；反之，capacity不变，同时析构一些不再需要的对象。resize是改变容器的大小，并创建对象。调用此函数时，可以引用容器中的对象，当加入新元素时，可以调用operator[]。
//reserve和resize都不会使capacity变小，但都有可能使capacity变大，具体怎么变大，reserve和resize是不一样的，reserve能准确控制capacity；而resize不能，vc里是每次增大一半当前的capacity。
//https://blog.csdn.net/linhao19841211_2/article/details/8154805
    //https://blog.51cto.com/10810429/1755428
    
    //不同capacity的vector进行赋值，会导致capacity和size不一致,如下vec capacity为20，size为10
    vec = vector<int>(10,1);
    
    
    
    //删除元素
    //删除最后一个
    vec.pop_back();
    
    //删除指定位置元素
    vec.erase(vec.begin());
    //区间删除
    vec.erase(vec.begin(), vec.begin()+1);
    
    //遍历删除
    vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {
        if (*it == 2) {
            it = vec.erase(it);   //删除后，迭代器指针会执行下一个位置并返回。
        }else{
            it++;
        }
    }
    for (; it != vec.end(); ) {
        if (*it == 2) {
            it = vec.erase(it);   //删除后，迭代器指针会执行下一个位置并返回。
        }else{
            it++;
        }
    }

    //清除所有
    vec.clear();
    
    //判断是否为空
    bool isEmpty = vec.empty();
    
    
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    
    //遍历元素
    //访问首尾
    int front = vec.front();
    int back = vec.back();
    vec.front() = 12;
    vec.back() = 13;
    
    //遍历-[]取值,越界不会报异常，直接崩溃
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    //遍历-at取值，越界报异常
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
    
    
    //遍历-迭代器遍历
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    for (auto it = vec.cbegin(); it != vec.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    /*
     cbegin返回一个const_iterator，指向容器的第一个元素。
     const_iterator是一个指向const内容的迭代器。你可以对这个迭代器进行加减操作。
     但是你不内能通过这个迭代器来修改其所指向的内容。
     begin返回的容是一个一般迭代器，可以通过该迭代器进行读写操作。cbegin显然不能进行写操作，只可以读。
     */
    
    //遍历-迭代器逆向遍历
    for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    
}
