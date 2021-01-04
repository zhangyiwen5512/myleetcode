//
// Created by zhangyiwen on 2020/12/30.
//

#ifndef CLEETCODE_SEARCH_H
#define CLEETCODE_SEARCH_H

#include <vector>

/*
 * 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转
 * （例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
 * 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 *
 * 输入：nums = [1], target = 0
 * 输出：-1
 *
 *
 * nums 中的每个值都 独一无二
 * nums 肯定会在某个点上旋转
 *
 *
 * target小于等于nums【-1】，从后往前开始匹配，当nums【i】>nums[-1]时返回或nums【j】<target时返回
 *
 * target大于等于nums【-1】，从前往后开始匹配，当nums【j】<nums[0]时返回或nums【j】>target时返回
 *
 *
 *
*/


class search {
public:
    int Solution(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (target >= nums[0])
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target)
                    return i;

                if (nums[i] < nums[0] || nums[i] > target)
                    return -1;
            }


        if (target <= nums[n - 1])
            for (int j = n - 1; j >= 0; --j) {
                if (nums[j] == target)
                    return j;

                if (nums[j] > nums[n- 1] || nums[j] < target)
                    return -1;
            }

        return -1;
    }
};


#endif //CLEETCODE_SEARCH_H
