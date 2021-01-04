from typing import List

"""
 * 给定一个包含n 个整数的数组nums和一个目标值target，
 * 判断nums中是否存在四个元素 a，b，c和 d，使得a + b + c + d的值与target相等？找出所有满足条件且不重复的四元组。
 * 注意：。
 * 答案中不可以包含重复的四元组。
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 *
 * 双指针同threesum
 *
"""


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)

        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
                break
            if nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target:
                continue

            for j in reversed(range(i + 3, n)):
                p = i + 1
                q = j - 1
                if j < n - 1 and nums[j] == nums[j + 1]:
                    continue

                while q > p:
                    temp = nums[i] + nums[j] + nums[p] + nums[q]
                    if target > temp:
                        x = nums[p]
                        while q > p and nums[p] == x:
                            p += 1
                    elif target == temp:
                        result.append([nums[i], nums[p], nums[q], nums[j]])
                        x = nums[p]
                        while q > p and nums[p] == x:
                            p += 1
                        x = nums[q]
                        while q > p and nums[q] == x:
                            q -= 1

                    else:
                        x = nums[q]
                        while q > p and nums[q] == x:
                            q -= 1

        return result
