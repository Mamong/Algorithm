//
//  auto_ptr.cpp
//  Algorithm
//
//  Created by marco on 2020/1/22.
//  Copyright © 2020 flywire. All rights reserved.
//

#include "auto_ptr.hpp"
#include <memory>
using namespace std;

void test(){
    /*
     STL 还提供了另一个模板类：auto_ptr 类。该类主要用于管理动态内存分配。

     如果使用 new() 函数分配堆中的内存，而又不记得回收这部分内存，会导致内存泄漏。因此必须使用 delete 语句释放该内存块。即使在函数末端添加了 delete 语句释放内存，还需要在任何跳出该函数的语句（如抛出异常）之前添加释放内存的处理，例如 goto 语句和 throw 语句。

     auto_ptr 模板定义了类似指针的对象，将 new 获得的地址赋给该对象。当 auto_ptr 对象过期时，析构函数将使用 delete 来释放内存。如果将 new 返回的地址赋值给 auto_ptr 对象，无须记住还需要释放这些内存。在 auto_ptr 对象过期时，内存将自动被释放。

     在 C++ 语言中，要使用 STL 中的 auto_ptr 对象，必须包含头文件 <memory>，该文件包括 auto_ptr 模板。使用通常的模板句法来实例化所需类型的指针。auto_ptr 构造函数是显式的，不存在从指针到 auto_ptr 对象的隐式类型转换。

     auto_ptr <double> pd;
     double *p_reg = new double;
     pd = p_reg; // 不允许
     pd = auto_ptr <double> (p_reg); //允许
     auto_ptr <double> panto =p_reg; //不允许
     auto_ptr <double> pauto (p_reg); //允许
     模板可以通过构造函数将 auto_ptr 对象初始化为一个常规指针。auto_ptr 是一个智能指针，但其特性远比指针要多。值得注意的是，在使用 auto_ptr 时，只能配对使用 new 和 delete。

     提示，只能对 new 分配的内存使用 auto_ptr 对象，不要对由 new() 分配的或通过声明变量分配的内存使用它。
     总结
     C++ 库中的 auto_ptr 对象是一种智能指针。智能指针是一种类，即其对象的特征结类似于指针。智能指针存储 new 分配的内存地址，也可以被解除引用。

     智能指针是一个类对象，可以修改和扩充简单指针的行为。智能指针可以建立引用计数，这使得多个对象可共享由智能指针跟踪的同一个值。当使用该值的对象数为 0 时，智能指针将删除该值。

     智能指针可以提高内存的使用效率，帮助防止内存泄露。
     */
    
    auto_ptr <double> pd;
    double *p_reg = new double;
    //pd = p_reg; // 不允许
    pd = auto_ptr <double> (p_reg); //允许
    //auto_ptr <double> panto =p_reg; //不允许
    auto_ptr <double> pauto (p_reg); //允许
}
