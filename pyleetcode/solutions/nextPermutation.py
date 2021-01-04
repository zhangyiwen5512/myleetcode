from typing import List

"""
 *
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 * 输入：nums = [1]
 * 输出：[1]
 *
 *
 * 较小数i是第一个从后开始，违反升序的数，
 * 较大数j是从后往前第一个大于较小数的，
 * 交换i和j，
 * 则i+1到n的数重新排序即可
 *
 *
 *          
"""


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i, j = n - 1, n - 1
        temp = nums[-1]
        while i >= 0 and nums[i] >= temp:
            temp = nums[i]
            i -= 1

        if i >= 0:
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1

            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp

        nums[i + 1:] = sorted(nums[i + 1:])

        print(nums)

