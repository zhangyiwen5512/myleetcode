from typing import List

'''
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入: "abcabcbb"
 * 输出: 3 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 找出最长子串，无重复字符
 * i到j-1不重复，则只要检查j是否在里面，
 * 不在则j+1,
 * 在则i=j‘+1，j'为重复的字符，偏移到j'+1的位置
 * st相同元素上次出现的位置,如果i大，说明[i,j-1]中没有与s[j]相同的元素，起始位置仍取i
 * 字符串的搜索用滑动窗口
'''


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        result = 0

        st = {}

        for last in range(len(s)):
            if s[last] in st:
                start = max(st[s[last]], start)
            result = max(result, last - start + 1)

            st[s[last]] = last + 1

        return result
