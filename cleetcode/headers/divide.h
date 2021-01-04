//
// Created by zhangyiwen on 2020/12/16.
//

#ifndef CLEETCODE_DIVIDE_H
#define CLEETCODE_DIVIDE_H

/*
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
 *
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 *
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 *
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
 *
 *
 *
 * dividend = -abs(dividend)
 * divisor = -abs(divisor)
 * 当dividend 《= divisor时，不断变大左移temp_divisor直到INT_MIN >> 1
 * 然后dividend-divisior
 * 循环往复
 *
 */


class divide {
public:
    int Solution(int dividend, int divisor) {
        int sign = (dividend > 0) ^ (divisor > 0);

        dividend = -abs(dividend);
        divisor = -abs(divisor);

        int ans = 0;

        while (dividend <= divisor){
            unsigned int temp_result = -1;
            unsigned int temp_divisor = divisor;
            while (dividend <= (temp_divisor << 1)){
                if (temp_divisor <= (INT_MIN >> 1))
                    break;

                temp_result = temp_result << 1;
                temp_divisor = temp_divisor << 1;
            }


            dividend -= temp_divisor;
            ans += temp_result;
        }



        if (sign == 0){
            if (ans == INT_MIN)
                return INT_MAX;
            return -ans;
        }
        else return ans;
    }
};


#endif //CLEETCODE_DIVIDE_H
