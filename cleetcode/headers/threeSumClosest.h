//
// Created by zhangyiwen on 2020/12/6.
//

#ifndef CLEETCODE_THREESUMCLOSEST_H
#define CLEETCODE_THREESUMCLOSEST_H
#include <vector>
/*
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
 * 使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 *
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 *
 *
 * 0 - nums[i],转化问题为求ℹ+1数组取两个数字他们的和为-nums[i],
 * 三层循环
 * 排序，ijk表示三个数
 * i从0到n - 1,num[i]!=nums[i-1],去掉重复的i
 * target - nums[j] - nums[k] - nums[i]
 * 大于则j++,直到nums【j】不与上一个重复
 * 小于则k--,直到nums【k】不与上一个重复
 *
 * 使用绝对值判断是否接近，得到最小的差值
 *
 *
 *
*/
class threeSumClosest {
public:
    int Solution(std::vector<int>& nums, int target) {
        int result = INT_MAX;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int temp = target - nums[i];
            int k = n - 1;
            int j = i + 1;
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            while (j < k and j < n){
                if (abs(temp - nums[j] - nums[k]) < abs(result))
                    result = temp - nums[j] - nums[k];

                if (temp > nums[j] + nums[k]){
                    int x = nums[j];
                    while (j < k and nums[j] == x)
                        j += 1;
                }

                else if (temp == nums[j] + nums[k])
                    return target;
                else{
                    int x = nums[k];
                    while (j < k and nums[k] == x)
                        k -= 1;
                }
            }
        }
        return target - result;
    }
};


#endif //CLEETCODE_THREESUMCLOSEST_H
