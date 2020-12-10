//
// Created by zhangyiwen on 2020/11/25.
//

#ifndef CLEETCODE_CONVERT_H
#define CLEETCODE_CONVERT_H
#include <string>

/*
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 *
 * 一行以及s只有一个字母为特例，直接返回
 * 一行一行计算
 * 定义mode = 2 * numRows - 2，
 * s[index], s[index + mode]将s[start + p]加载中间
 * start为index所在列的起始序号，p为定位偏移
 *
*/

class convert {
public:
    std::string Solution(std::string s, int numRows) {
        if (numRows == 1) return s;
        if (s.length() == 1) return s;

        std::string result;
        int mode = 2 * numRows - 2;

        for (int i = 0; i < numRows ; ++i) {
            int index = i;
            while (index < s.length()){
                result += s[index];
                int p = mode - index % mode;
                int start = index / mode * mode;
                if (p != 0 && (p != mode / 2) && p != mode && (start + p < s.length())){
                    result += s[start + p];
                }
                index += mode;
            }
        }

        return result;
    }
};


#endif //CLEETCODE_CONVERT_H
