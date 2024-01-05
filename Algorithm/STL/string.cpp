//
//  string.cpp
//  Algorithm
//
//  Created by marco on 2019/7/23.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "string.hpp"
#include <iostream>
#include <string>
using namespace std;

void test()
{
    
    
    /**
     
      string 类提供的各种操作函数大致分为八类：构造器和析构器、大小和容量、元素存取、字符串比较、字符串修改、字符串接合、I/O 操作以及搜索和查找。
     
      表 1 string 类的所有成员函数 函数名称     功能
     构造函数     产生或复制字符串
     析构函数     销毁字符串
     =，assign     赋以新值
     Swap     交换两个字符串的内容
     + =，append( )，push_back()     添加字符
     insert ()     插入字符
     erase()     删除字符
     clear ()     移除全部字符
     resize ()     改变字符数量
     replace()     替换字符
     +     串联字符串
     ==，！ =，<，<=，>，>=，compare()     比较字符串内容
     size()，length()     返回字符数量
     max_size ()     返回字符的最大可能个数
     empty ()     判断字符串是否为空
     capacity ()     返回重新分配之前的字符容量
     reserve()     保留内存以存储一定数量的字符
     [],at()     存取单一字符
     >>，getline()     从 stream 中读取某值
     <<     将值写入 stream
     copy()     将内容复制为一个 C - string
     c_str()     将内容以 C - string 形式返回
     data()     将内容以字符数组形式返回
     substr()     返回子字符串
     find()     搜寻某子字符串或字符
     begin( )，end()     提供正向迭代器支持
     rbegin()，rend()     提供逆向迭代器支持
     get_allocator()     返回配置器

     */
    
    /*
     
     构造函数有四个参数，其中三个具有默认值。要初始化一个 string 类，可以使用 C 风格字符串或 string 类型对象，也可以使用 C 风格字符串的部分或 string 类型对象的部分或序列。

     注意，不能使用字符或者整数去初始化字符串。
     常见的 string 类构造函数有以下几种形式：
     */
    int char_len=5;
    char cstr[] = "hello,world";
    
    int stridx = 1,strbegin=0,strlen=5;
    string str = "hello,world";
    
    int num = 3;
    char c = 'c';
    
    string strs; //生成空字符串
    string s1(str); //生成字符串str的复制品
    string s2(str, stridx); //将字符串str中始于stridx的部分作为构造函数的初值
    string s3(str, strbegin, strlen); //将字符串str中始于strbegin、长度为strlen的部分作为字符串初值
    string s4(cstr); //以C_string类型cstr作为字符串s的初值
    string s5(cstr,char_len);    //以C_string类型cstr的前char_len个字符串作为字符串s的初值
    string s6(num, c); //生成一个字符串，包含num个c字符
    string s7(str.begin(), str.end());    //以区间[beg, end]内的字符作为字符串s的初值
    
    
    /*
     析构函数的形式如下：

     ~string() //销毁所有内存，释放内存
     如果字符串只包含一个字符，使用构造函数对其初始化时，使用以下两种形式比较合理：

     std::string s('x');    //错误
     std::string s(1, 'x');    //正确
     或

     std::string s("x");    //正确
     C_string 一般被认为是常规的 C++ 字符串。目前，在 C++ 中确实存在一个从 const char * 到 string 的隐式型别转换，却不存在从 string 对象到 C_string 的自动型别转换。对于 string 类型的字符串，可以通过 c_str() 函数返回该 string 类对象对应的 C_string。

     通常，程序员在整个程序中应坚持使用 string 类对象，直到必须将内容转化为 char* 时才将其转换为 C_string。
     */
    
    
    
    
    /*
     String 类型对象包括三种求解字符串长度的函数：size() 和 length()、 maxsize() 和 capacity()：

         size() 和 length()：这两个函数会返回 string 类型对象中的字符个数，且它们的执行效果相同。
         max_size()：max_size() 函数返回 string 类型对象最多包含的字符数。一旦程序使用长度超过 max_size() 的 string 操作，编译器会拋出 length_error 异常。
         capacity()：该函数返回在重新分配内存之前，string 类型对象所能包含的最大字符数。


     string 类型对象还包括一个 reserve() 函数。调用该函数可以为 string 类型对象重新分配内存。重新分配的大小由其参数决定。reserve() 的默认参数为 0。
     
     #include <iostream>
     #include <string>
     using namespace std;
     int main ()
     {
         int size = 0;
         int length = 0;
         unsigned long maxsize = 0;
         int capacity=0;
         string str ("12345678");
         string str_custom;
         str_custom = str;
         str_custom.reserve (5);
         size = str_custom.size();
         length = str_custom.length();
         maxsize = str_custom.max_size();
         capacity = str_custom.capacity();
         cout << "size = " << size << endl;
         cout << "length = " << length << endl;
         cout << "maxsize = " << maxsize << endl;
         cout << "capacity = " << capacity << endl;
         return 0;
     }
     
     程序执行结果为：

     size = 8
     length = 8
     maxsize = 2147483647
     capacity = 15
     由此程序可知，string 类型对象 str_custom 调用 reserve() 函数时，似乎并没有起到重新分配内存的目的（笔者所用编译器为 Visual C++6.0）。

     修改上述代码，删除语句 str_custom.reserve (5)，在代码 str_custom = str 之后如下添加代码：

     str_custom.resize (5);
     修改后程序的执行结构如下：

     size = 5
     length = 5
     maxsize = 2147483647
     capacity = 15
     重新设置 string 类型对象 str_custom 的大小之后，重新求解 str_custom 的大小，其执行效果与设置的数值一致（均为 5）。
     */
    
    
    /*
     在通常情况下，string 是 C++ 中的字符串。字符串是一种特殊类型的容器，专门用来操作字符序列。

     字符串中元素的访问是允许的，一般可使用两种方法访问字符串中的单一字符：下标操作符[] 和 成员函数at()。两者均返回指定的下标位置的字符。第 1 个字符索引（下标）为 0，最后的字符索引为 length()-1。

     需要注意的是，这两种访问方法是有区别的：

         下标操作符 [] 在使用时不检查索引的有效性，如果下标超出字符的长度范围，会示导致未定义行为。对于常量字符串，使用下标操作符时，字符串的最后字符（即 '\0'）是有效的。对应 string 类型对象（常量型）最后一个字符的下标是有效的，调用返回字符 '\0'。
         函数 at() 在使用时会检查下标是否有效。如果给定的下标超出字符的长度范围，系统会抛出 out_of_range 异常。

     */
    
    
    /*
     字符串可以和类型相同的字符串相比较，也可以和具有同样字符类型的数组比较。

     Basic_string 类模板既提供了  >、<、==、>=、<=、!= 等比较运算符，还提供了 compare() 函数，其中 compare() 函数支持多参数处理，支持用索引值和长度定位子串进行比较。该函数返回一个整数来表示比较结果。如果相比较的两个子串相同，compare() 函数返回 0，否则返回非零值。
     compare()函数
     类 basic_string 的成员函数 compare() 的原型如下：

     int compare (const basic_string& s) const;
     int compare (const Ch* p) const;
     int compare (size_type pos, size_type n, const basic_string& s) const;
     int compare (size_type pos, size_type n, const basic_string& s,size_type pos2, size_type n2) const;
     int compare (size_type pos, size_type n, const Ch* p, size_type = npos) const;
     如果在使用 compare() 函数时，参数中出现了位置和大小，比较时只能用指定的子串。例如：

     s.compare {pos,n, s2);
     若参与比较的两个串值相同，则函数返回 0；若字符串 S 按字典顺序要先于 S2，则返回负值；反之，则返回正值。下面举例说明如何使用 string 类的 compare() 函数。
     
     #include <iostream>
     #include <string>
     using namespace std;
     int main ()
     {
         string A ("aBcdef");
         string B ("AbcdEf");
         string C ("123456");
         string D ("123dfg");
         //下面是各种比较方法
         int m=A.compare (B); //完整的A和B的比较
         int n=A.compare(1,5,B,4,2); //"Bcdef"和"AbcdEf"比较
         int p=A.compare(1,5,B,4,2); //"Bcdef"和"Ef"比较
         int q=C.compare(0,3,D,0,3); //"123"和"123"比较
         cout << "m = " << m << ", n = " << n <<", p = " << p << ", q = " << q << endl;
         cin.get();
         return 0;
     }
     
     程序的执行结果为：

     m = 1, n = -1, p = -1, q = 0
     由此可知，string 类的比较 compare() 函数使用非常方便，而且能区分字母的大小写。建议读者多使用此函数。
     比较运算符
     String 类的常见运算符包括 >、<、==、>=、<=、!=。其意义分别为"大于"、"小于"、"等于"、"大于等于"、"小于等于"、"不等于"。

     比较运算符使用起来非常方便，此处不再介绍其函数原型，读者直接使用即可。下面以例 2 进行说明。

     #include <iostream>
     #include <string>
     using namespace std;
     void TrueOrFalse (int x)
     {
         cout << (x?"True":"False")<<endl;
     }
     int main ()
     {
         string S1 = "DEF";
         string CP1 = "ABC";
         string CP2 = "DEF";
         string CP3 = "DEFG";
         string CP4 ="def";
         cout << "S1= " << S1 << endl;
         cout << "CP1 = " << CP1 <<endl;
         cout << "CP2 = " << CP2 <<endl;
         cout << "CP3 = " << CP3 <<endl;
         cout << "CP4 = " << CP4 <<endl;
         cout << "S1 <= CP1 returned ";
         TrueOrFalse (S1 <=CP1);
         cout << "S1 <= CP2 returned ";
         TrueOrFalse (S1 <= CP2);
         cout << "S1 <= CP3 returned ";
         TrueOrFalse (S1 <= CP3);
         cout << "CP1 <= S1 returned ";
         TrueOrFalse (CP1 <= S1);
         cout << "CP2 <= S1 returned ";
         TrueOrFalse (CP2 <= S1);
         cout << "CP4 <= S1 returned ";
         TrueOrFalse (CP4 <= S1);
         cin.get();
         return 0;
     }
     
     程序运行结果为：

     S1= DEF
     CP1 = ABC
     CP2 = DEF
     CP3 = DEFG
     CP4 = def
     S1 <= CP1 returned False
     S1 <= CP2 returned True
     S1 <= CP3 returned True
     CP1 <= S1 returned True
     CP2 <= S1 returned True
     CP4 <= S1 returned False
     由上述内容可知，使用比较运算符可以非常容易地实现字符串的大小比较。在使用时比较运算符时，读者应注意，对于参加比较的两个字符串，任一个字符串均不能为 NULL，否则程序会异常退出。

     */
    
    
    
    
    /*
      字符串内容的修改
     可以通过使用多个函数修改字符串的值。例如 assign()，operator=，erase()，交换（swap），插入（insert）等。另外，还可通过 append() 函数添加字符。

     下面逐一介绍各成员函数的使用方法。
     assign()函数
     使用 assign() 函数可以直接给字符串赋值。该函数既可以将整个字符串赋值给新串，也可以将字符串的子串赋值给新串。其在 basic_string 中的原型为：
      basic_string& assign (const E*s); //直接使用字符串赋值
     basic_string& assign (const E*s, size_type n);
     basic_string& assign (const basic_string & str, size_type pos, size_type n);
     //将str的子串赋值给调用串
     basic_string& assign (const basic_string& str);    //使用字符串的“引用”賦值
     basic_string& assign (size_type n, E c) ; //使用 n个重复字符賦值
     basic_string& assign (const_iterator first, const_iterator last);    //使用迭代器赋值
     以上几种方法在例 1 中均有所体现。请读者参考下述代码。
     #include <iostream>
     #include <string>
     using namespace std;
     int main()
     {
         string str1 ("123456");
         string str;
         str.assign (str1); //直接赋值
         cout << str << endl;
         str.assign (str1, 3, 3); //赋值给子串
         cout << str << endl;
         str.assign (str1,2,str1.npos);//赋值给从位置 2 至末尾的子串
         cout << str << endl;
         str.assign (5,'X'); //重复 5 个'X'字符
         cout << str << endl;
         string::iterator itB;
         string::iterator itE;
         itB = str1.begin ();
         itE = str1.end();
         str.assign (itB, (--itE)); //从第 1 个至倒数第 2 个元素，赋值给字符串 str
         cout << str << endl;
         return 0;
     }
      operator= 函数
     operator= 的功能就是赋值。
     
     
     erase()函数
     erase函数的原型如下：
     （1）string& erase ( size_t pos = 0, size_t n = npos );
     （2）iterator erase ( iterator position );
     （3）iterator erase ( iterator first, iterator last );
     也就是说有三种用法：
     （1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
     （2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
     （3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
     
     erase() 函数的使用方法为：
     str.erase (str* begin(), str.end());
     或 str.erase (3);
     
     
     swap()函数
     swap()函数的原型为：

     void swap (basic_string& str);
     swap()函数的使用方法为：
     string str2 ("abcdefghijklmn");
     str.swap (str2);//单纯地成员变量的交换，指针交换，代价小
     或者swap(str, str2);//产生了一个临时对象，拷贝构造，再赋值，再赋值，代价大，效率低
     
     insert()函数
     insert () 函数的原型为：

     basic_string& insert (size_type p0 , const E * s); //插人 1 个字符至字符串 s 前面
     basic_string& insert (size_type p0 , const E * s, size_type n); // 将 s 的前 3 个字符插入p0 位置
     basic_string& insert (size_type p0, const basic_string& str);
     basic_string& insert (size_type p0, const basic_string& str,size_type pos, size_type n); //选取 str 的子串
     basic_string& insert (size_type p0, size_type n, E c); //在下标 p0 位置插入  n 个字符 c
     iterator insert (iterator it, E c); //在 it 位置插入字符 c
     void insert (iterator it, const_iterator first, const_iterator last); //在字符串前插入字符
     void insert (iterator it, size_type n, E c) ; //在 it 位置重复插入 n 个字符 c
     insert() 函数的使用方法为：
     string A("ello");
     string B ;
     B.insert(1,A);
     cout << B << endl;
     A = "ello";
     B = "H";
     B.insert (1,"yanchy ",3);
     cout<< B <<endl;
     A = "ello";
     B = "H";
     B.insert (1,A,2,2);
     cout << B << endl;
     A="ello";
     B.insert (1 , 5 , 'C');
     cout << B << endl;
     A = "ello";
     string::iterator it = B.begin () +1;
     const string:: iterator itF = A.begin();
     const string:: iterator itG = A.end();
     B.insert(it,itF,itG);
     cout << B << endl;
     
      append 函数
     append() 函数的原型为：

     basic_string& append (const E * s); //在原始字符串后面追加字符串s
     basic_string& append (const E * s, size_type n);//在原始字符串后面追加字符串 s 的前 n 个字符
     basic_string& append (const basic_string& str, size_type pos,size_type n);//在原始字符串后面追加字符串 s 的子串 s [ pos,…,pos +n -1]
     basic_string& append (const basic_string& str);
     basic_string& append (size_type n, E c); //追加 n 个重复字符
     basic_string& append (const_iterator first, const_iterator last); //使用迭代器追加
     
     A = "ello";
     cout << A << endl;
     cout << B << endl;
     B.append(A);
     cout << B << endl;
     A = "ello";
     cout << A << endl;
     cout << B << endl;
     B.append("12345",2);
     cout << B << endl;
     A = "ello";
     cout << A << endl;
     cout << B << endl;
     B.append("12345",2,3);
     cout << B << endl;
     A = "ello";
     B = "H";
     cout << A << endl;
     cout << B << endl;
     B.append (10, 'a');
     cout << B << endl;
     A = "ello";
     B = 'H';
     cout << A << endl ;
     cout << B << endl;
     B.append(A.begin(), A, end());
     cout << B << endl;
     
      字符串内容的替换
     如果在一个字符串中标识出具体位置，便可以通过下标操作修改指定位置字符的值，或者替换某个子串。完成此项操作需要使用 string 类的成员函数 replace()。

     replace() 函数的原型如下：

     basic_string& replace (size_type p0, size_type n0, const E * s); //使用字符串 s 中的 n 个字符，从源串的位置 P0 处开始替换
     basic_string& replace (size_type p0, size_type n0, const E *s, size_type n); //使用字符串 s 中的 n 个字符，从源串的位置 P0 处开始替换 1 个字符
     basic_string& replace (size_type p0, size_type n0, const basic_string& str); //使用字符串 s 中的 n 个字符，从源串的位置 P0 处开始替换
     basic_string& replace (size_type p0, size_type n0, const basic_string& str, size_type pos, size_type n); //使用串 str 的子串 str [pos, pos + n-1] 替换源串中的内容，从位置 p0 处开始替换，替换字符 n0 个
     basic_string& replace (size_type p0, size_type n0, size_type n, E c); //使用 n 个字符 'c' 替换源串中位置 p0 处开始的 n0 个字符
     basic_string& replace (iterator first0, iterator last0, const E * s);//使用迭代器替换，和 1) 用法类似
     basic_string& replace (iterator first0, iterator last0, const E * s, size_type n);//和 2) 类似
     basic_string& replace (iterator first0, iterator last0, const basic_string& str); //和 3) 类似
     basic_string& replace (iterator first0, iterator last0, size_type n, E c); //和 5) 类似
     basic_string& replace (iterator first0, iterator last0, const_iterator first, const_iterator last); //使用迭代器替换
     */
    
    
    /*
     C++字符串输入输出操作详解
     "<<" 和 ">>" 提供了 C++ 语言的字符串输入和字符串输出功能。"<<" 可以将字符读入一个流中（例如 ostream）；">>" 可以实现将以空格或回车为 "结束符" 的字符序列读入到对应的字符串中，并且开头和结尾的空白字符不包括进字符串中。

     还有一个常用的 getline() 函数，该函数的原型包括两种形式：

     template <class CharType, class Traits, class Allocator > basic_istream<CharType, Traits>& getline (basic_istream<CharType, Traits>& _Istr,basic_string <CharType，Traits, Allocator> &_Str);
     //上述原型包含 2 个参数：第 1 个参数是输入流；第 2 个参数是保存输入内容的字符串
     template <class CharType, class Traits, class Allocator> basic_istream<CharType, Traits>& getline (basic_istream <CharType, Traits>&_ Istr, basic_string <CharType, Traits, Allocator>& _Str,CharType_Delim);
     //上述原型包含 3 个参数：第 1 个参数是输入流，第 2 个参数保存输入的字符串，第 3 个参数指定分界符。
     该函数可将整行的所有字符读到字符串中。在读取字符时，遇到文件结束符、分界符、回车符时，将终止读入操作，且文件结束符、分界符、回车符在字符串中不会保存；当已读入的字符数目超过字符串所能容纳的最大字符数时，将会终止读入操作。
     */
    //C++输入
    string stuff;
    cin>>stuff;
    //或
    getline(cin,stuff);
    
    
    
    /*
     C++字符串查找函数详解
     在 C 语言和 C++ 语言中，可用于实现字符串查找功能的函数非常多。在 STL 中，字符串的查找功能可以实现多种功能，比如说：

         搜索单个字符、搜索子串；
         实现前向搜索、后向搜索；
         分别实现搜索第一个和最后一个满足条件的字符（或子串）；


     若查找 find() 函数和其他函数没有搜索到期望的字符（或子串），则返回 npos；若搜索成功，则返回搜索到的第 1 个字符或子串的位置。其中，npos 是一个无符号整数值，初始值为 -1。当搜索失败时， npos 表示“没有找到（not found）”或“所有剩佘字符”。

     值得注意的是，所有查找 find() 函数的返回值均是 size_type 类型，即无符号整数类型。该返回值用于表明字符串中元素的个数或者字符在字符串中的位置。
     
      find()函数和 rfind()
     find() 函数的原型主要有以下 4 种：

     size_type find (value_type _Chr, size_type _Off = 0) const;
     //find()函数的第1个参数是被搜索的字符、第2个参数是在源串中开始搜索的下标位置
     size_type find (const value_type* _Ptr , size_type _Off = 0) const;
     //find()函数的第1个参数是被搜索的字符串，第2个参数是在源串中开始搜索的下标位置
     size_type find (const value_type* _Ptr, size_type _Off = 0, size_type _Count) const;
     //第1个参数是被搜索的字符串，第2个参数是源串中开始搜索的下标，第3个参数是关于第1个参数的字符个数，可能是 _Ptr 的所有字符数，也可能是 _Ptr 的子串宇符个数
     size_type find (const basic_string& _Str, size_type _Off = 0) const;
     //第1个参数是被搜索的字符串，第2参数是在源串中开始搜索的下标位置
     rfind() 函数的原型和find()函数的原型类似，参数情况也类似。只不过 rfind() 函数适用于实现逆向查找。

      find_first_of()函数和 find_last_of()函数
     find_first_of() 函数可实现在源串中搜索某字符串的功能，该函数的返回值是被搜索字符串的第 1 个字符第 1 次出现的下标（位置）。若查找失败，则返回 npos。

     find_last_of() 函数同样可实现在源串中搜索某字符串的功能。与 find_first_of() 函数所不同的是，该函数的返回值是被搜索字符串的最后 1 个字符的下标（位置）。若查找失败，则返回 npos。

     上述两个函数的原型分别为：

     size_type find_first_not_of (value_type_Ch, size_type_Off = 0) const; size_type find_first_of (const value_type* _Ptr, size_type _Off = 0) const;
     size_type find_first_of (const value_type* _Ptr, size_type_Off, size_type_Count) const;
     size_type find_first_of (const basic_string & _Str, size_type_Off = 0) const;
     size_type find_last_of (value_type _Ch, size_type_Off = npos) const;
     size_type find_last_of (const value_type* _Ptr, size_type_Off = npos) const;
     size_type find_last_of (const value_type* _Ptr, size_type _Off, size_type _Count) const;
     size_type find_last_of (const basic_string& _Str, size_type_Off = npos) const;
     
     
      find_first_not_of()函数和 find_last_not_of()函数
     find_first_not_of() 函数的函数原型为：

     size_type find_first_not_of (value_type _Ch, size_type_Off = 0) const;
     size_type find_first_not_of (const value_type * _Ptr, size_type_Off = 0) const;
     size_type find_first_not_of (const value_type* _Ptr, size_type_Off, size_type_Count) const;
     size_type find_first_not_of (const basic_string & _Str, size_type_Off = 0) const;
     find_first_not_of() 函数可实现在源字符串中搜索与指定字符（串）不相等的第 1 个字符；find_last_not_of() 函数可实现在源字符串中搜索与指定字符（串）不相等的最后 1 个字符。这两个函数的参数意义和前面几个函数相同，它们的使用方法和前面几个函数也基本相同。
     */
    //find函数返回类型 size_type
    string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i");
    string flag;
    string::size_type position;

    //find 函数 返回jk 在s 中的下标位置
    position = s.find("jk");
    if (position != s.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
    {
    cout << "position is : " << position << endl;
    }
    else
    {
    cout << "Not found the flag" + flag;
    }
    
    /*
     C++ string支持迭代器方法详解
     STL 定义了 5 种迭代器，根据所需的迭代器类型对算法进行描述。这 5 种迭代器分别是：输入迭代器、输出迭代器、正向迭代器、双向迭代器和随机访问迭代器。对于这 5 种迭代器不仅可以执行解除引用操作（* 操作符），还可进行比较。本节主要讲述 basic_string（或 string 类）中迭代器的使用。

     basic.string 和 string 类均提供了常规的迭代器和反向迭代器。string 是字符的有序群集。

     C++ 标准库为 string 提供了相应接口，便于将字符串作为 STL 容器使用。可以使用迭代器遍历 string 内的所有字符；也可以使用其他算法遍历 string 内的所有字符。而且能够访问字符串中的每个字符，并对这些字符进行排序、逆向重排、找出最大值等操作。

     string 类的迭代器是随机存取迭代器，即支持随机存取。任何一个 STL 算法都可与其搭配使用。通常 string 的“迭代器型别”由 string class 本身定义，通常可以被简单地定义为一般指针。对迭代器而言，如果发生重新分配，或其所指的值发生某些变化时，迭代器会失效。

     string 类中和使用迭代器相关的成员函数是很多的，主要包括 begin()、end()、rbegin ()、rend()、append()、assign()、insert()、erase()、replace() 等。
     
     #include <iostream>
     #include <string>
     #include <algorithm>
     using namespace std;
     int main ()
     {
         string s ("The zip code of Hondelage in Germany is 38108.");
         cout << "Original: " << s << endl;
         string sd(s.begin(),s.end ()); //构造函数中使用迭代器
         cout << "Destination: " << sd << endl;
         transform (sd.begin(), sd.end(), sd.begin(), toupper); //算法中使用迭代器(仿函数)
         cout << "Destination (All Toupper)): " << sd << endl;
         string sd1;
         sd1.append (sd.begin(),(sd.end() -7)); //append()函数中使用迭代器
         cout << "Destination sd1: " << sd1 << endl;
         string sd2;
         string::reverse_iterator iterA;
         string temp = "0";
         for (iterA = sd.rbegin (); iterA != sd.rend (); iterA++) //reverse_iterator
         {
             temp=* iterA;
             sd2.append (temp);
         }
         cout << "Destination sd2: " << sd2 << endl;
         sd2.erase (0, 15); //erase()函数中使用迭代器
         cout << "Destination sd2 (Erased 15 chars) : " << sd2 << endl;
         string::iterator iterB = sd2.begin ();
         string sd3 = string ("12345678");
         sd2.insert (sd2.begin(), sd3.begin(), sd3.end()); //insert()函数中使用迭代器
         cout << "Destination sd2 (Insert 8 chars) : " << sd2 << endl;
         sd2.replace (sd2.begin (), sd2.end(), "This is an Exarrple of Replace"); //Replace
         cout <<"Destination sd2 (Replace All): " << sd2 << endl; // replace ()函数中使用迭代器
     }
     */
    
    
    /*
     C++ string支持配置器方法详解
     配置器最早是为将内存模型抽象化而提出的。所以使用内存配置器分配内存时，是按对象的个数进行的，而不是按字节数。这有别于原来的 new [] 和 new 操作符。配置器最大的优点在于，配置器实现了将算法、容器与物理存储细节分隔。配置器可以提供一套分配与释放内存的标准方式，并提供用作指针类型和引用类型的标准名称。目前而言，配置器仅是一种纯粹的抽象。行为上类似分配器的类型都可看作配置器。

     C++ STL 提供了标准分配器，目的是为用户提供更多的服务。basic_string 模板以及 string 类均提供了对常见配置器的相关支持。basic_string 类模板中包含 1 个配置器类型的成员 allocator_type。对于 string 对象，allocator_type 可以作为配置器类的对象使用；对 string 类而言，allocator_type 等价于 allocator<char>，即分配数据类型为 char 的内存，便于 string 类的对象存储 char 型字符。

     同时 basic_string 类模板的第 3 个参数也是配置器模板参数。basic_string 类模板的形式如下：

     template <class CharType, class Traits = char_traits <CharType>, class Allocator=allocator<CharType>> class basic_string
     而 string 类的声明形式如下：

     typedef basic_string <char> string;
     对于 basic_string 类模板，其第 1 个参数是 CharType，第 2 个参数和第 3 个参数的默认值和 CharType 均相关。在声明 string 类时，参数 char 取代模板中的 CharType，string 即成为模板的实例，同时模板中的第 3 个参数成为 "class Allocator = allocator <char>"，其意义为 string 中对象的内存类型为 char 型。

     string 类还提供了 1 个和配置器相关的函数 get_allocator()，其函数原型为：

     allocator_type string:: get_allocator () const
     函数返回 string 类的内存模型对象，可以用于构造新的字符串。以如下程序为例介绍该函数的使用方法。
     
     #include <iostream>
     #include <string>
     #include <memory>
     using namespace std;
     int main ()
     {
         string s("abed");
         basic_string <char> s1 (s.get_allocator());
         basic_string <char> :: allocator_type aT = s1.get_allocator ();
         string::size_type se = s1.size ();
         cout << se << endl;
     }
      由于在 string 类中，allocator 是保护成员，难以直接调用对内存的直接配置。对于配置器，一般情况下都是使用默认配置器。对于本节内容，读者了解即可。
     */
    
    string strss("helloworld");
    string strSub = strss.substr(0, 5);
    
    //c++11
    string s11 = to_string(123); // 将123这个数字转成字符串串 cout << s1 << endl;
    string s21 = to_string(4.5); // 将4.5这个数字转成字符串串 cout << s2 << endl;
    cout << s11 + s21 << endl; // 将s1和s2两个字符串串拼接起来并输出
    printf("%s\n", (s11 + s21).c_str()); // 如果想⽤用printf输出string，得加⼀一 个.c_str()
    
    string str2 = "123";
    int a = stoi(str2);
    cout << a;
    str2 = "123.44";
    double b = stod(str2);
    cout << b;
    /**
     stoi如果遇到的是⾮非法输⼊入(⽐比如stoi("123.4")，123.4不不是⼀一个int型变量量):
     1.会⾃自动截取最前⾯面的数字，直到遇到不不是数字为⽌止 (所以说如果是浮点型，会截取前⾯面的整数部分) 2.如果最前⾯面不不是数字，会运⾏行行时发⽣生错误
     stod如果是⾮非法输⼊入:
     1.会⾃自动截取最前⾯面的浮点数，直到遇到不不满⾜足浮点数为⽌止
     2.如果最前⾯面不不是数字或者⼩小数点，会运⾏行行时发⽣生错误
     3.如果最前⾯面是⼩小数点，会⾃自动转化后在前⾯面补0
     
     不仅有stoi、stod两种，相应的还有:
     stof (string to float)
     stold (string to long double)
     stol (string to long)
     stoll (string to long long)
     stoul (string to unsigned long)
     stoull (string to unsigned long long)
     */
}
