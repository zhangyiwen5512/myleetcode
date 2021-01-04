//
// Created by zhangyiwen on 2020/12/15.
//

#ifndef CLEETCODE_STRSTR_H
#define CLEETCODE_STRSTR_H

#include <string>

/*
 * 实现 strStr() 函数。
 * 给定一个haystack 字符串和一个 needle 字符串，
 * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回 -1
 *
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 *
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 *
 * 从0到len(haystack) - len(needle)
 * 比较haystack[i:i+n]和needle
 *
 *
 */

class strStr {
public:
    int Solution(std::string haystack, std::string needle) {
        if (needle == "")
            return 0;
        int n = needle.length();
        if (haystack.length() < n)
            return -1;
        for (int j = 0; j <= haystack.length() - n; ++j) {
            if (haystack.substr(j, n) == needle)
                return j;
        }

        return -1;
    }
};


#endif //CLEETCODE_STRSTR_H
