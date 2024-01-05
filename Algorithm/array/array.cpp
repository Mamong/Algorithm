//
//  array.cpp
//  Algorithm
//
//  Created by marco on 2019/8/28.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "array.hpp"
#include <vector>
#include <map>
#include <unordered_map>

#include <queue>

#include "common.hpp"

//Contains Duplicate I (检测数组中是否包含重复的元素)
//LeetCode 217
bool containsDuplicate(std::vector<int>& nums) {
    
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]==nums[i-1]) {
            return true;
        }
    }
    return false;
}

//Majority Element (出现次数超过数组长度一半的元素)
//LeetCode 169
int majorityElement(std::vector<int> &num){
    int targetNumber = 0;
    int count = 0;
    for (int i = 0; i < num.size(); i++) {
        if (count == 0) {
            targetNumber = num[i];
            count = 1;
        }else{
            if (targetNumber == num[i]) {
                count++;
            }else{
                count--;
            }
        }
    }
    return targetNumber;
}

//Single Number (数组中只出现过一次的数字)
//[LeetCode 136](https://leetcode.com/problems/majority-element/description/)
//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i <nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}

//Missing Number (寻找数组中缺失的数字)
//LeetCode 268
//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//思路：求和减去；异或所有，再异或完整集合
int missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int ret = (n + 1)*n/2;
    for (int i = 0; i < n; i++){
        ret -= nums[i];
    }
    return ret;
}

//Move Zeros (将所有的0移动到数组末尾)
//LeetCode 283
void moveZeroes(std::vector<int>& nums) {
    int k = 0;

    for ( int i = 0; i < nums.size(); i++){
        if (nums[i] != 0) {
            if (i != k) {
                swap(nums[i], nums[k]);
            }
            k++;
        }
    }
}

//Remove Element (移除数组中等于某个值的元素)
//LeetCode 27
int removeElement(std::vector<int>& nums, int val) {
    int k = 0;
    
    for ( int i = 0; i < nums.size(); i++){
        if (nums[i] != val) {
            if (i != k) {
                nums[k] = nums[i];
            }
            k++;
        }
    }
    return k;
}

//Two Sum II (有序数组内部的两个元素的和为目标值)
//LeetCode 167
std::vector<int> twoSumII(std::vector<int>& numbers, int target) {
    
    int l = 0;
    int r = numbers.size() - 1;
    
    while ( l < r){
        
        if (numbers[l] + numbers[r] == target){
            int res[] = {l+1,r+1};
            return std::vector<int>(res,res+2);
            
        }else if (numbers[l] + numbers[r] < target){
            l++;
        } else{
            r--;
        }
    }
    return std::vector<int>();
    
}

//Minimum Size Subarray Sum (无序数组和大于或等于某值的最小子数组)
//LeetCode 209
int minSubArrayLen(int s, std::vector<int>& nums) {
    int l = 0;
    int r = -1;
    int result = nums.size()+1;
    int sum = 0;
    
    while (l<nums.size()) {
        if (r+1<nums.size() && sum < s) {
            r++;
            sum+=nums[r];
        }else{
            //r+1=nums.size()
            sum-=nums[l];
            l++;
        }
        if (sum>=s) {
            result = std::min(result,r-l+1);
        }
    }
    if (result == nums.size()+1) {
        result = 0;
    }
    return result;
}

//Intersection of Two Arrays (两个数组的交点元素)
//LeetCode 349
//遍历其中一个，查找另一个的元素，找到则插到一个临时x数组


//Top Kth Frequent (出现频率最高的前k个元素)
//LeetCode 347
//unordered_map计数，priority_queue通过插入弹出排序，控制size为k
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    
    std::unordered_map<int, int>freqMap;//<value,freq>
    
    //生成一个map
    for (int i = 0; i < nums.size(); ++i) {
        freqMap[nums[i]]++;
    }
    
    if (k > freqMap.size()){
        return std::vector<int>();
    }
    
    //pair:freq,value
    //iter：map里面的每一个元素
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > pq;
    
    for (std::unordered_map<int,int>::iterator iter = freqMap.begin();iter != freqMap.end(); iter++) {
        
        if (pq.size() == k) {
            
            if (iter->second > pq.top().first) {
                
                pq.pop();
                pq.push(std::make_pair(iter->second, iter->first));
            }
            
        } else {
            
            pq.push(std::make_pair(iter->second, iter->first));
        }
    }
    
    std::vector<int>res;
    while (!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
    
}

//The Kth largest element in array (数组中第k大的元素)
//LeetCode 215
//heap
int findKthLargest1(std::vector<int>& nums, int k) {
    
    std:make_heap(nums.begin(), nums.end());//heap sort
    
    for (int i=0; i<k-1; i++){
        pop_heap(nums.begin(), nums.end());//将front放在end前部，剩下的元素构成新的heap，堆排序
        nums.pop_back();//删除最后一个元素
    }
    return nums[0];
}

//sort
int findKthLargest2(std::vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}

//priority_queue
int findKthLargest3(std::vector<int>& nums, int k) {
    
    std::priority_queue<int> q(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        q.pop();
    }
    return q.top();
}

//partition
int __partition(std::vector<int>& nums, int low, int high);

int findKthLargest4(std::vector<int>& nums, int k) {
    
    k--;//eg. the second large number's index is 1
    int l = 0;
    int r = nums.size() - 1;
    int index= 0;
    
    while ( l < r){
        
        index = __partition(nums,l,r);
        
        if ( k < index ){
            r = index - 1;
        }else if ( k > index ){
            l = index + 1;
        }else {
            return nums[index];
        }
    }
    
    return nums[l];
}

int __partition(std::vector<int>& nums, int low, int high){
    
    int l = low;
    int r = high;
    int pivot = nums[low];
    
    while (l < r){
        
        //smaller than pivot is on the right
        while (l < r && nums[r] <= pivot){
            r--;
        }
        nums[l] = nums[r];
        
        //bigger than pivot is on the left
        while (l < r && nums[l] >= pivot){
            l++;
        }
        nums[r] = nums[l];
        
    }
    nums[l] = pivot;
    return l;
}

//Merge Two Sorted Array (合并两个有序的数组)
//LeetCode 88


//Two Sum I (无序数组内部的两个元素的和为目标值)
//LeetCode 1
