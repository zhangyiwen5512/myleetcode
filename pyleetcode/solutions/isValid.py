from typing import List

'''
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 *
 * 输入: "()"
 * 输出: true
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 输入: "(]"
 * 输出: false
 *
 * 输入: "([)]"
 * 输出: false
 * 
 * 输入: "{[]}"
 * 输出: true
 *
 * 左括号进栈，continue
 * 其他字符continue
 * 又括号桟非空，出桟且相互匹配，continue。否则False
 *
 * 结尾桟空则True
 * 否则False
 *
'''


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(len(s)):
            if s[i] in '({[':
                stack.append(s[i])
                continue
            elif s[i] not in ')}]':
                continue

            if stack:
                if s[i] == ']' and stack[-1] == '[':
                    stack.pop(-1)
                elif s[i] == ')' and stack[-1] == '(':
                    stack.pop(-1)
                elif s[i] == '}' and stack[-1] == '{':
                    stack.pop(-1)
                else:
                    return False
            else:
                return False

        if stack == []:
            return True
        else:
            return False
