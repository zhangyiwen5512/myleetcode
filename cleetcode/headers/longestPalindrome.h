//
// Created by zhangyiwen on 2020/11/24.
//

#ifndef CLEETCODE_LONGESTPALINDROME_H
#define CLEETCODE_LONGESTPALINDROME_H

#include <vector>
/*
  * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 *
 * 若字串是回文串，则start-1 == end+1即可判断为回文串，长度大于3的都可以这样计算
 * 长度为一，是回文串
 * 长度为2，则字母重复则是
 *
*/
class longestPalindrome {
public:
    std::string Solution(std::string s) {

        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); ++i) {
            std::vector<int >temp1 = this->findone(i, i, s);
            std::vector<int >temp2 = this->findone(i, i + 1, s);
            if (temp1[1] - temp1[0] > end - start){
                start = temp1[0];
                end = temp1[1];
            }
            if (temp2[1] - temp2[0] > end - start){
                start = temp2[0];
                end = temp2[1];
            }
        }

        std::string result(s.begin() + start, s.begin() + end + 1);

        return result;
    }

    std::vector<int > findone(int start, int end, std::string s){
        while (start >= 0 && end < s.length()){
            if (s[start] == s[end]){
                end += 1;
                start -= 1;
            } else{
                break;
            }
        }
        std::vector<int > result(2,0);
        result[0] = start + 1;
        result[1] = end - 1;
        return result;
    }

};


#endif //CLEETCODE_LONGESTPALINDROME_H
