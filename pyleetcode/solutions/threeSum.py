
from typing import List

"""
 * 给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，使得a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *      [-1, 0, 1],
 *      [-1, -1, 2]
 * ]
 * 
 *
 * 0 - nums[i],转化问题为求ℹ+1数组取两个数字他们的和为-nums[i],
 * 三层循环
 * 排序，ijk表示三个数
 * i从0到n - 1,num[i]!=nums[i-1],否则重复了
 * j要大于i且nums[j]!=num[j-1]，否则重复了
 * k=n-1，k>j, k--直到num[i],nums[j],nums[k]为0并加入结果中，
 * 
"""


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)

        for i in range(n):
            target = 0 - nums[i]
            k = n - 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1 ,n):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                while j < k and nums[j] + nums[k] > target:
                    k -= 1

                if k == j:
                    break

                if target == nums[j] + nums[k]:
                    result.append([nums[i], nums[j], nums[k]])


        return result

        # result = []

        # while len(nums) > 2:
        #     target = 0 - nums[0]
        #
        #     temp = {}
        #     value = 0
        #     nums.pop(0)
        #     index = 0
        #     for index, value in enumerate(nums):
        #         if target - value in temp:
        #             # t = sorted([nums[0], target - value, value])
        #             # result[str(t[0]) + str(t[1]) + str(t[2])] = [nums[0], target - value, value]
        #             result.append([nums[0], target - value, value])
        #         temp[value] = index
        #
        #     nums.pop(index)
        #     nums.pop(temp[target - value])
        #     nums.pop(0)
        #
        #
        # return result


