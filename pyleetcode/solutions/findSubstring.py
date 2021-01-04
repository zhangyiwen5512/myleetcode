from typing import List

"""
 * 给定一个字符串 s 和一些长度相同的单词 words。
 * 找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 *
 *
 * 输入：
 * s = "barfoothefoobarman",
 * words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 *
 * 输入：
 * s = "wordgoodgoodgoodbestword",
 * words = ["word","good","best","word"]
 * 输出：[]
 *
 * 找出每个单词在s中的位置为起始头，
 * 滑动窗口w，判断窗口中的是否在words中，在则继续，否则返回
"""
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        l = len(words[0])
        n = len(words)
        already = set()
        ans = []
        end = len(s) - l * n

        def find(s, words, start):
            number = len(words)
            if number == 0:
                return ans.append(start - n * l)

            if s[start:start + l] in words:
                words.remove(s[start:start + l])
                find(s, words, start + l)
                words.append(s[start:start + l])

        for i in range(n):
            if words[i] in already:
                continue

            already.add(words[i])
            temp = 0
            index_list = []
            while temp <= end:
                index = s.find(words[i], temp)
                if index != -1 and index <= end:
                    index_list.append(index)
                    temp = index + 1
                else:
                    break

            for index in index_list:
                find(s, words[:i] + words[i + 1:], index + l)

        return ans