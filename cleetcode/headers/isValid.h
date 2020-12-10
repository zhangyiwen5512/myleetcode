//
// Created by zhangyiwen on 2020/12/9.
//

#ifndef CLEETCODE_ISVALID_H
#define CLEETCODE_ISVALID_H

#include <string>
#include <stack>
/*
 *
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
 */

class isValid {
public:
    bool Solution(std::string s) {
        std::stack<char> stack1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack1.push(s[i]);
                continue;
            }
            else if (s[i] != ')' && s[i] != '}' && s[i] != ']')
                continue;

            if (!stack1.empty()){
                if (s[i] == ']' && stack1.top() == '[')
                    stack1.pop();
                else if (s[i] == ')' && stack1.top() == '(')
                    stack1.pop();
                else if (s[i] == '}' && stack1.top() == '{')
                    stack1.pop();
                else return false;
            } else
                return false;

        }
        return stack1.empty();

    }
};


#endif //CLEETCODE_ISVALID_H
