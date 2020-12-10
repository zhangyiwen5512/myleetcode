//
// Created by zhangyiwen on 2020/12/5.
//

#ifndef CLEETCODE_THREESUM_H
#define CLEETCODE_THREESUM_H
#include <vector>
/*
 * 给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，使得a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *      [-1, 0, 1],
 *      [-1, -1, 2]
 * ]
 *
 * 0 - nums[i],转化问题为求ℹ+1数组取两个数字他们的和为-nums[i],
 * 三层循环
 * 排序，ijk表示三个数
 * i从0到n - 1,num[i]!=nums[i-1],否则重复了
 * j要大于i且nums[j]!=num[j-1]，否则重复了
 * k=n-1，k>j, k--直到num[i],nums[j],nums[k]为0并加入结果中，
*/
class threeSum {
public:
    std::vector<std::vector<int>> Solution(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int target = 0 - nums[i];
            int k = n - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                while (j < k && nums[j] + nums[k] > target)
                    --k;

                    if (k == j)
                        break;

                if (target == nums[j] + nums[k])
                    result.push_back({nums[i], nums[j], nums[k]});

            }

        }


        return result;
    }
};


#endif //CLEETCODE_THREESUM_H
