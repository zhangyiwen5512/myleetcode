//
// Created by zhangyiwen on 2020/12/1.
//

#ifndef CLEETCODE_MAXAREA_H
#define CLEETCODE_MAXAREA_H
#include <vector>


/*
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别
 * 为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 说明：你不能倾斜容器。
 *
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 输入：height = [1,1]
 * 输出：1
 *
 * 输入：height = [4,3,2,1,4]
 * 输出：16
 *
 * 输入：height = [1,2,1]
 * 输出：2
 *
 *
 *
 * n = height.length
 * 2 <= n <= 3 * 104
 * 0 <= height[i] <= 3 * 10^4
 *
 *
 * size = (j - i) * min(height[i], height[j])
 * height[i] 和 height[j]谁更小就缩进一格
 *
 *
 *
 *
 *
 * 动态规划
 *
*/

class maxArea {
public:
    int Solution(std::vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int size = (j - i) * std::min(height[i], height[j]);

        while (i < j){
            if (height[i] < height[j])
                ++i;
            else
                --j;

            size = std::max(size, (j - i) * std::min(height[i], height[j]));

        }
        return size;
    }
};


#endif //CLEETCODE_MAXAREA_H
