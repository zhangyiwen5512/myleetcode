from typing import List

'''
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
 * 去掉，组成新数组和数组2求第k-k/2小的元素,
 * 
 *
 *
 *
 

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
'''


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def findKthElement(arr1, arr2, k):
            m, n = len(arr1), len(arr2)
            if m > n:
                return findKthElement(arr2, arr1, k)

            if not arr1:
                return arr2[k - 1]

            if k == 1:
                return min(arr1[0], arr2[0])

            # 求各自中位数
            # i, j = min(m, k // 2) - 1, min(n, k // 2) - 1
            i, j = min(k // 2, m) - 1, min(k // 2, n) - 1
            if arr1[i] > arr2[j]:
                return findKthElement(arr1, arr2[j + 1:], k - j - 1)
            else:
                return findKthElement(arr1[i + 1:], arr2, k - i - 1)

        left = (len(nums1) + len(nums2) + 1) // 2
        right = (len(nums2) + len(nums1) + 2) // 2

        return (findKthElement(nums1, nums2, left) + findKthElement(nums1, nums2, right)) / 2
