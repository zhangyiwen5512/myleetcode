//
// Created by zhangyiwen on 2020/12/29.
//

#ifndef CLEETCODE_LONGESTVALIDPARENTHESES_H
#define CLEETCODE_LONGESTVALIDPARENTHESES_H

#include <string>
#include <vector>
/*
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 *
 * dp[i] = 长度
 * ()情况，则s[i] = s[i -2] == ), s[i - 1] = (，    （【ℹ-2】）
 * dp[i] = dp[i - 2] + 2
 *
 * ))情况,则s[i] = ), s[i - 1] = ), s[i - dp[i - 1] - 1] = (，    【i - dp[i - 1] - 2】+（【i-1】）
 * dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
 *
 *
 *
 *
 *
 */

class longestValidParentheses {
public:
    int Solution(std::string s) {
        int n = s.length();
        std::vector<int >dp (n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')'){
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i >= 2)
                        dp[i] += dp[i - 2];
                }else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] >= 2) {
                        dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
            }
            ans = std::max(ans, dp[i]);
        }

        return ans;

    }
};


#endif //CLEETCODE_LONGESTVALIDPARENTHESES_H
