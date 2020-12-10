//
// Created by zhangyiwen on 2020/12/3.
//

#ifndef CLEETCODE_ROMANTOINT_H
#define CLEETCODE_ROMANTOINT_H
#include <string>

/*
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 例如， 罗马数字 2 写做II，即为两个并列的 1。12 写做XII，即为X+II。 27 写做XXVII, 即为XX+V+II。
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做IIII，而是IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减
 * 小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 *
 * 输入: "III"
 * 输出: 3
 *
 * 输入: "IV"
 * 输出: 4
 *
 * 输入: "IX"
 * 输出: 9
 *
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V = 5, III = 3.
 *
 * 输入: "MCMXCIV"
 * 出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 *
 * 从左到又依次匹配对应的字符，加上对应的值
 *
 */

class romanToInt {
public:
    int Solution(std::string s) {
        std::vector<int >values = {900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1};
        std::vector<std::string >symbols = {"CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I"};
        int result = 0;

        while (s != ""){
            for (int i = 0; i < values.size(); ++i) {
                int index = s.find(symbols[i]);
                if (index != std::string::npos){
                    result += values[i];
                    if (symbols[i].length() == 1)
                        s = s.substr(0, index) + s.substr(index + 1);
                    else
                        s = s.substr(0, index) + s.substr(index + 2);
                }
                if (s == "") break;
            }
        }

        return result;

//        std::vector<int >values = {900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1};
//        std::vector<std::string >symbols = {"CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I"};
//        int result = 0;
//
//        while (s != ""){
//            for (int i = 0; i < values.size(); ++i) {
//                int index = s.find(symbols[i]);
//                if (index != std::string::npos){
//                    result += values[i];
//                    if (symbols[i].length() == 1)
//                        s = s.substr(0, index) + s.substr(index + 1);
//                    else
//                        s = s.substr(0, index) + s.substr(index + 2);
//                }
//                if (s == "") break;
//            }
//        }
//
//        return result;


    }
};


#endif //CLEETCODE_ROMANTOINT_H
