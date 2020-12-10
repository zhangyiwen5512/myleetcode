from typing import List

"""
 * 给定一个包括n 个整数的数组nums和 一个目标值target。找出nums中的三个整数，
 * 使得它们的和与target最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 *
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 *
 *
 *
 *
 *
 *
"""

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        result = 2**31 - 1
        nums.sort()
        n = len(nums)
        for i in range(n):

            temp = target - nums[i]
            k = n - 1
            j = i + 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            while j < k and j < n:
                if abs(temp - nums[j] - nums[k]) < abs(result):
                    result = temp - nums[j] - nums[k]

                if temp > nums[j] + nums[k]:
                    x = nums[j]
                    while j < k and nums[j] == x:
                        j += 1
                elif temp == nums[j] + nums[k]:
                    return target
                else:
                    x = nums[k]
                    while j < k and nums[k] == x:
                        k -= 1

        return target - result