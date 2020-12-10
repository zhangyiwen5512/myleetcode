//
// Created by zhangyiwen on 2020/11/26.
//

#ifndef CLEETCODE_REVERSE_H
#define CLEETCODE_REVERSE_H

/*
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 输入: 123
 * 输出: 321
 *
 * 输入: -123
 * 输出: -321
 *
 * 输入: 120
 * 输出: 21
 *
 *
 * x对10取余数求得每一位，加到result上
 * x/10下一位求余数
 *
 *
 *
*/
class reverse {
public:
    int Solution(int x) {
        if (x == INT_MIN or x == INT_MAX)
            return 0;

        int result = 0;
        int sign = 1;
        if (x < 0){
            sign = -1;
            x = -x;
        }

        while (true){
            result += x % 10;
            x = x / 10;
            if (x == 0) break;
            if (INT_MAX / 10 < result or INT_MIN / 10 > result)
                return 0;
            result = result * 10;
        }

        return result * sign;
    }
};



#endif //CLEETCODE_REVERSE_H
