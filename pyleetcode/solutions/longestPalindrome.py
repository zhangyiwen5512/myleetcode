

"""
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 * 若字串是回文串，则start-1 == end+1即可判断为回文串，长度大于3的都可以这样计算
 * 长度为一，是回文串
 * 长度为2，则字母重复则是
 *
 *
 *
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        end = 0
        for i in range(len(s)):
            l1, r1 = self.findone(i, i, s)
            l2, r2 = self.findone(i, i + 1, s)
            if r1 - l1 > end - start:
                start = l1
                end = r1
            if r2 - l2 > end - start:
                start = l2
                end = r2

        return s[start:end + 1]


    def findone(self, start, end, s):
        while start >= 0 and end < len(s):
            # right & left
            if s[start] == s[end]:
                end += 1
                start -= 1
            else:
                break

        return start + 1, end - 1

