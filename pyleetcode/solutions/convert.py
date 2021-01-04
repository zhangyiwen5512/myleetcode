import os

"""
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 *
 * 一行以及s只有一个字母为特例，直接返回
 * 一行一行计算
 * 定义mode = 2 * numRows - 2，
 * s[index], s[index + mode]将s[start + p]加载中间
 * start为index所在列的起始序号，p为定位偏移
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) == 1:
            return s
        if numRows == 1:
            return s

        result = ""
        mode = 2 * numRows - 2

        for j in range(numRows):
            index = j
            while index < len(s):
                result += s[index]
                p = mode - index % mode
                start = index // mode * mode
                if (p != mode // 2) and p != mode and start + p < len(s):
                    result += s[start + p]

                index += mode

        return result
