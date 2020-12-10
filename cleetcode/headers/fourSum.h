//
// Created by zhangyiwen on 2020/12/6.
//

#ifndef CLEETCODE_FOURSUM_H
#define CLEETCODE_FOURSUM_H

#include <vector>
/*
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 注意：。
 * 答案中不可以包含重复的四元组。
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 *
 * 双指针同threesum
 *
*/

class fourSum {
public:
    std::vector<std::vector<int>> Solution(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int n = nums.size();
        int p = 0;
        int q = 0;
        int temp = 0;
        int x = 0;

        for (int i = 0; i < n - 3 ; ++i) {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;

            for (int j = n - 1; j >= i + 3 ; --j) {
                p = i + 1;
                q = j - 1;
                if (j < n - 1 and nums[j] == nums[j + 1])
                    continue;

                while (q > p){
                    temp = nums[i] + nums[j] + nums[p] + nums[q];
                    if (target > temp){
                        x = nums[p];
                        while (q > p and nums[p] == x)
                            p += 1;
                    } else if (target == temp){
                        result.push_back({nums[i], nums[p], nums[q], nums[j]});
                        x = nums[p];
                        while (q > p and nums[p] == x)p += 1;

                        x = nums[q];
                        while (q > p and nums[q] == x)q -= 1;

                    } else{
                        x = nums[q];
                        while (q > p and nums[q] == x)q -= 1;
                    }
                }
            }
        }
        return result;
    }
};


#endif //CLEETCODE_FOURSUM_H
