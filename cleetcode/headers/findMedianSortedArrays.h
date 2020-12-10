//
// Created by zhangyiwen on 2020/11/23.
//

#ifndef CLEETCODE_FINDMEDIANSORTEDARRAYS_H
#define CLEETCODE_FINDMEDIANSORTEDARRAYS_H
#include<vector>
#include<algorithm>
#include <limits.h>
/*
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 *
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 *
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 *
 * 取两个数组中的第k/2个元素进行比较,如果数组1的元素小于数组2的元素，则说明数组1中的前k/2个元素不可能成为第k个元素的候选，
 * 去掉，组成新数组和数组2求第k-k/2小的元素, 特殊情况k==1,比较首元素，一个为空
 *
 * 寻找第K大的变种
 *

 nums1.length == m
 nums2.length == n
 0 <= m <= 1000
 0 <= n <= 1000
 1 <= m + n <= 2000
 -106 <= nums1[i], nums2[i] <= 106
*/

class findMedianSortedArrays {
public:
    double Solution(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findK(nums1, nums2, 0, 0, left) + findK(nums1, nums2, 0, 0, right)) / 2.0;
    }


    // i,j 为起始位置
    int findK(std::vector<int>& arr1, std::vector<int>& arr2, int i, int j, int k){
        int m = arr1.size();
        int n = arr2.size();

        if (i >= m){
            return arr2[j + k - 1];
        }

        if (j >= n){
            return arr1[i + k - 1];
        }

        if (k == 1){
            return std::min(arr1[i], arr2[j]);
        }

        int middlei = ((i + k / 2 - 1) < m) ? arr1[i + k / 2 - 1] : INT_MAX;
        int middlej = ((j + k / 2 - 1) < n) ? arr2[j + k / 2 - 1] : INT_MAX;

        if (middlei < middlej){
            return findK(arr1, arr2, i + k / 2, j, k - k / 2);
        } else{
            return findK(arr1, arr2, i, j + k / 2, k - k / 2);
        }

    }

};


#endif //CLEETCODE_FINDMEDIANSORTEDARRAYS_H
