//
// Created by zhangyiwen on 2020/11/28.
//

#ifndef CLEETCODE_MYATOI_H
#define CLEETCODE_MYATOI_H

#include <string>
//#include <algorithm>

/*
 * 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 *
 * 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
 *
 * 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
 * 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
 * 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
 * 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
 *
 * 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
 *
 * 提示：
 *
 * 本题中的空白字符只包括空格字符 ' ' 。
 * 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (23^1 − 1) 或 INT_MIN (−2^31) 。
 *
 * 输入: "42"
 * 输出: 42
 *
 * 输入: "   -42"
 * 输出: -42
 * 解释: 第一个非空白字符为 '-', 它是一个负号。
 *     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
 *
 * 输入: "4193 with words"
 * 输出: 4193
 * 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
 * 输入: "words and 987"
 * 输出: 0
 * 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
 *      因此无法执行有效的转换
 * 输入: "-91283472332"
 * 输出: -2147483648
 * 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
 *     因此返回 INT_MIN (−231)
 *
 * 去掉空格
 * 判断符号
 * 数字ascii x < 58 and x > 47，则result = result * 10 + (x - 48)
 * 碰到字符则推出
 * 检查边界
 *
*/
class myAtoi {
public:
    int Solution(std::string s) {
        int space = 0;
        for (char i : s) {
            if (32 == i) ++space;
            else break;
        }
        s = s.substr(space);
        if (s.empty()) return 0;

        int sign = 1;
        int i = 0;
        if (45 == s[0]){
            sign = -1;
            i = 1;
        } else if(s[0] == 43)
            i = 1;
        else
            i = 0;

        int result = 0;

        while (i < s.length()) {
            if (s[i] < 58 and s[i] > 47) {
                if (result > (INT_MAX - s[i] + 48) / 10) {
                    return !(sign - 1)? INT_MAX : INT_MIN;
                }

                result = result * 10 + (s[i] - 48);
            }
            else
                break;
            ++i;
        }

        return result * sign;
    }
};

#endif //CLEETCODE_MYATOI_H
