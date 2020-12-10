
from typing import List


"""
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 *
 * 
 * 匹配则与下一个字符串匹配，不匹配则去掉最后一个字母
 * 
"""


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == []:
            return ""
        pos = 0
        for i in range(len(strs)):
            if len(strs[i]) < len(strs[pos]):
                pos = i

        result = strs[pos]

        for i in range(len(strs)):
            if i == pos:
                continue

            while strs[i][:len(result)] != result:
                result = result[:-1]
                if result == "":
                    return ""

        return result