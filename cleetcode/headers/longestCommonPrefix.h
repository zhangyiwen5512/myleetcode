//
// Created by zhangyiwen on 2020/12/4.
//

#ifndef CLEETCODE_LONGESTCOMMONPREFIX_H
#define CLEETCODE_LONGESTCOMMONPREFIX_H
#include <vector>
#include <string>
/*
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
*/
class longestCommonPrefix {
public:
    std::string Solution(std::vector<std::string>& strs) {
        if (strs.size() == 0) return "";
        int pos = 0;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].length() < strs[pos].length()) pos = i;
        }

        std::string result = strs[pos];

        for (int j = 0; j < strs.size(); ++j) {
            if (j == pos) continue;

            while (strs[j].find(result) != 0){
                result = result.substr(0, result.length() - 1);
                if (result == "") return "";
            }
        }

        return result;
    }
};


#endif //CLEETCODE_LONGESTCOMMONPREFIX_H
