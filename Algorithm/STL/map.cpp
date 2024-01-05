//
//  map.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "map.hpp"
#include <map>
#include <string>
#include <iostream>

using namespace std;


/*
 
 map和multimap是一个键值映射的容器。map中的键值对都是唯一的，但是multimap中一个键可以对应多个值。
 
 map和multimap是关联式容器，键值成对存在
 map和multimap是红黑变体的平衡二叉树结构
 map只支持唯一的键值对，集合中的元素是按照一定的顺序排列的
 multimap中的键可以出现多次
 map和multimap的元素插入过程是按照顺序插入的
 
 作者：一月二十三
 链接：https://www.jianshu.com/p/497843e403b4
 来源：简书
 简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
 
 
 */

void MapDemo::test(){
    
    map<int, string> map3{{1,"1"},{2,"2"}};
    map<int, string> map4{map3};
    map<int, string> map5{map3.begin(),map3.end()};

    
    map<int, string> map1;
    
    /*
     map元素的插入，有两种方式：
     
     调用insert函数插入pair类型的键值对
     直接使用[]来对键进行复制，类似于Objective-C中的NSMutableDictionary赋值一样。
     
     map的insert函数返回的是pair类型，pair的第二个参数表示是否插入成功。如果插入的元素键名相同，则插入失败。
     */
    
    //insert方法插入
    //--1 通过pair<int, string>(1,”chenhua“) 构造pair元素
    map1.insert(pair<int, string>(1,"chenhua"));
    map1.insert(pair<int, string>{11,"chenhua"});

    //--2 通过make_pair构造pair元素
    map1.insert(make_pair(2,"mengna"));
    //--3 通过value_type构造pair元素
    map1.insert(map<int, string>::value_type(3,"chenmeng"));
    
    //[]直接插入
    map1[4] = "menghua";
    
    //重复插入(插入会不成功)
    pair<map<int, string>::iterator,bool> pair1 = map1.insert(make_pair(2, "menghua"));
    if (pair1.second) {
        cout << "重复插入成功" << endl;
    }else{
        cout << "重复插入失败" << endl;
    }
    
    
    //构造元素
    //https://blog.csdn.net/windpenguin/article/details/75581552
    
    
    //获取元素
    //map 的成员函数 at() 返回的是参数键对应的对象。如果这个键不存在，就会拋出 out_of_range 异常。
    auto value = map1.at(1);
    //map 容器提供了以键为参数的下标运算符，它可以返回一个和键所关联对象的引用。
    auto value2 = map1[1];
    //下标运算的使用并不是简单的检索机制。
   //如果键不存在，元素默认的构造函数会用键和键所关联的对象生成一个新元素，如果键关联的对象是基本数据类型，它的值为0。
    auto value3 = map1[10];
    //可以用下标运算符来更新 map 中的元素，如果元素不在 map 中，也可以用它插入元素。下标运算主要用在左赋值上，用来修改已存在的元素
    map1[5] = "menghua";

    
    //元素的删除
    //删除值为"haha"的元素
    //erase的参数可以是key，返回删除的个数，也就是0或1；
    //参数可以是迭代器，返回的迭代器指向被删的下一个位置。参数必须是有效的迭代器，如果是最后一个元素，则返回结束迭代器。
    //erase也可以通过传入两个迭代器来指定一个范围。
    for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
        if (it->second.compare("haha") == 0) {
            map1.erase(it);
        }
    }
    map1.erase(1);
    
    //遍历
    for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
    
    
    //查找
    //查找key=100的键值对
    map<int, string>::iterator it = map1.find(100);
    if (it != map1.end()) {
        cout << "存在key=100的键值对";
    }else{
        cout << "不存在" << endl;
    }
    
    //查找key = 1000的位置
    //返回两个迭代器，第一个表示<=1000的迭代器位置，第二个是>1000的迭代器位置，是查找一个等于关键字的闭开区间
    pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(1000);
    if (mypair.first == map1.end()) {
        cout << "等于1000的位置不存在" << endl;
    }else{
        cout << mypair.first->first << "\t" << mypair.first->second << endl;
    }
    
    if (mypair.second == map1.end()) {
        cout << "大于1000的位置不存在" << endl;
    }else{
        cout << mypair.second->first << "\t" << mypair.second->second << endl;
    }
}
