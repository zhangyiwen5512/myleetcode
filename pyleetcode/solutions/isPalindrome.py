import os

"""
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 输入: 121
 * 输出: true
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 从尾部取数字，反倒头顶，组成的新数与之相等
 *
 *
"""
INT_MAX = 2 ** 31 - 1


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        temp = 0
        x1 = x
        while x1 != 0:
            if temp > (INT_MAX - x1 % 10) / 10:
                return False
            temp = temp * 10 + x1 % 10
            x1 = x1 // 10

        return temp == x
