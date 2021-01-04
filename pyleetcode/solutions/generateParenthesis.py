from typing import List

"""
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 输入：n = 3
 * 输出：[
 *       "((()))",
 *        "(()())",
 *       "(())()",
 *       "()(())",
 *       "()()()"
 *     ]
 * 当s长度==2倍n时加入ans
 * 当左边小于n时可以加入一个左括号
 * 当右边小于左边时可以加入一个右括号
 *
"""


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def gen(left, right, s):
            if len(s) == 2 * n:
                ans.append(s)
                return

            if left < n:
                gen(left + 1, right, s + '(')

            if left > right:
                gen(left, right + 1, s + ')')

        gen(0, 0, "")

        return ans
