//
// Created by zhangyiwen on 2020/11/30.
//

#ifndef CLEETCODE_ISMATCH_H
#define CLEETCODE_ISMATCH_H
#include <string>
#include <vector>

/*
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
 *
 * 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 输入：s = "mississippi" p = "mis*is*p*."
 * 输出：false
 *
 *
 * 提示：
 * 0 <= s.length <= 20
 * 0 <= p.length <= 30
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 *
 * 动态规划
 *
*/

class isMatch {
public:
    bool Solution(std::string s, std::string p) {
        int i = s.length();
        int j = p.length();
        std::vector<std::vector<bool >> dp(i + 1, std::vector<bool >(j + 1, false));
        dp[0][0] = true;

        for (int k = 0; k < i + 1; ++k) {
            for (int l = 1; l < j + 1; ++l) {
                if (p[l - 1] == '*'){
                    dp[k][l] = dp[k][l] | dp[k][l - 2];
                    if (this->match(k, l - 1, s, p))
                        dp[k][l] =  dp[k][l] | dp[k - 1][l];
                } else
                    if (this->match(k, l, s, p))
                        dp[k][l] =  dp[k][l] | dp[k - 1][l - 1];
            }
        }

        return dp[i][j];
    }

    bool match(int i, int j, std::string s, std::string p){
        if (i == 0)
            return false;
        if ('.' == p[j - 1])
            return true;

        return s[i - 1] == p[j - 1];
    }
};


#endif //CLEETCODE_ISMATCH_H
