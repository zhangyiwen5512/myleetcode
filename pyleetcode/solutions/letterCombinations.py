from typing import List

"""
* 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 *
 *
 *
 * 只要digits还有字符，表示没完字符串进入下一次操作，否则将ans加入列表
 * 取digits首数字对应的字母分别加到ans上，进入下一次操作
 *
 *
 *
 *
 * 
 *
 *
"""


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        table = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        ans = []
        n = len(digits)

        def combination(index, c):
            if index == n:
                ans.append(c)
                return
            button = table[digits[index]]
            for i in range(len(button)):
                combination(index + 1, c + button[i])

        if digits != '':
            combination(0, "")

        return ans
