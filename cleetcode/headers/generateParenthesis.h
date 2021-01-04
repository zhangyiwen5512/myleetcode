//
// Created by zhangyiwen on 2020/12/10.
//

#ifndef CLEETCODE_GENERATEPARENTHESIS_H
#define CLEETCODE_GENERATEPARENTHESIS_H
#include <string>
#include <vector>

/*
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 输入：n = 3
 * 输出：[
 *       "((()))",
 *        "(()())",
 *       "(())()",
 *       "()(())",
 *       "()()()"
 *     ]
 *
 * 当s长度==2倍n时加入ans
 * 当左边小于n时可以加入一个左括号
 * 当右边小于左边时可以加入一个右括号
 */

class generateParenthesis {
public:
    std::vector<std::string> Solution(int n) {
        std::vector<std::string> ans;
        this->gen(0, 0, "", ans, n);

        return ans;

    }

    void gen(int left, int right, std::string s, std::vector<std::string>& ans, int n){
        if (s.length() == 2 * n){
            ans.push_back(s);
            return;
        }


        if (left < n)
            gen(left + 1, right, s + '(', ans, n);

        if (left > right)
            gen(left, right + 1, s + ')', ans, n);

    }
};


#endif //CLEETCODE_GENERATEPARENTHESIS_H
