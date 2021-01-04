import os

"""
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 输入：s = "aa" p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 * 输入：s = "aa" p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 * 输入：s = "ab" p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 * 输入：s = "aab" p = "c*a*b"
 * 输出：true
 * 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 
 * 输入：s = "mississippi" p = "mis*is*p*."
 * 输出：false
 *
 *
 * 提示：
 * 0 <= s.length<= 20
 * 0 <= p.length<= 30
 * s可能为空，且只包含从a-z的小写字母。
 * p可能为空，且只包含从a-z的小写字母，以及字符.和*。
 * 保证每次出现字符* 时，前面都匹配到有效的字符
 * 
 * 动态规划
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def macth(i, j):
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        i, j = len(s), len(p)

        dp = [[False] * (j + 1) for _ in range(i + 1)]
        dp[0][0] = True

        for m in range(i + 1):
            for n in range(1, j + 1):
                if p[n - 1] == "*":
                    dp[m][n] |= dp[m][n - 2]
                    if macth(m, n - 1):
                        dp[m][n] |= dp[m - 1][n]
                else:
                    if macth(m, n):
                        dp[m][n] |= dp[m - 1][n - 1]

        return dp[i][j]
