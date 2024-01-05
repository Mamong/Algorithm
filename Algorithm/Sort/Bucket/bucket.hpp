//
//  bucket.hpp
//  Algorithm
//
//  Created by marco on 2019/3/21.
//  Copyright © 2019 flywire. All rights reserved.
//

#ifndef bucket_hpp
#define bucket_hpp

#include <stdio.h>


/*
 桶排序
 
 基本思想
 
 桶排序的基本思想是将一个数据表分割成许多buckets，然后每个bucket各自排序，或用不同的排序算法，或者递归的使用bucket sort算法。也是典型的divide-and-conquer分而治之的策略。它是一个分布式的排序，介于MSD基数排序和LSD基数排序之间。
 
 
 基本流程
 
 建立一堆buckets；
 遍历原始数组，并将数据放入到各自的buckets当中；
 对非空的buckets进行排序；
 按照顺序遍历这些buckets并放回到原始数组中即可构成排序后的数组。
 
 
 https://www.cnblogs.com/ECJTUACM-873284962/p/6935506.html
 
 
 将待排序集合中元素移动到对应的桶中，复杂度为O(n) ；
 对每个桶中元素进行排序，并移动回初始集合中，若桶个数为M，平均每个桶中元素个数为N/M，则复杂度为O(M*N/MlogN/M+N) O(N+N(logN-logM))。当M==N时，即桶排序向计数排序方式演化，则堆排序不发挥作用，复杂度为O(N)，只需要将元素移动回初始集合即可。当M==1时，即桶排序向比较性质排序算法演化，对集合进行堆排序，并将元素移动回初始集合，复杂度为O(N+NlogN) 。
 
和计数排序类似，适用于元素数值分布集中的序列。
 
 https://www.jianshu.com/p/204ed43aec0c
 */

#endif /* bucket_hpp */
