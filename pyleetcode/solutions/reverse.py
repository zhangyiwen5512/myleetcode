import os

"""
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 输入: 123
 * 输出: 321
 *
 * 输入: -123
 * 输出: -321
 *
 * 输入: 120
 * 输出: 21
 *
 * 
 * x对10取余数求得每一位，加到result上
 * x/10下一位求余数
 *
 *
 *
"""


class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        if x < 0:
            sign = -1
            x = -x
        else:
            sign = 1
        while True:
            result += x % 10
            x = x // 10
            if x == 0:
                break
            if (2 ** 31 - 1) / 10 < result or -2 ** 31 / 10 > result:
                return 0
            result = result * 10

        return result * sign
