//
// Created by zhangyiwen on 2020/12/27.
//

#ifndef CLEETCODE_NEXTPERMUTATION_H
#define CLEETCODE_NEXTPERMUTATION_H

#include <vector>

/*
 *
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 * 输入：nums = [1]
 * 输出：[1]
 *
 *
 * 较小数i是第一个从后开始，违反升序的数，
 * 较大数j是从后往前第一个大于较小数的，
 * 交换i和j，
 * 则i+1到n的数重新排序即可
 *
 *
 */

class nextPermutation {
public:
    void Solution(std::vector<int>& nums) {

        int i = nums.size() - 1;
        int j = i;
        int temp = nums[i];
        while (i >= 0 && nums[i] >= temp){
            temp = nums[i];
            i -= 1;
        }

        while (j >= 0 && nums[j] <= nums[i]){
            j -= 1;
        }

        if (i >= 0){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        std::sort(nums.begin() + i + 1, nums.end());
    }
};





#endif //CLEETCODE_NEXTPERMUTATION_H
