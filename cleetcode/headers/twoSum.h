//
// Created by zhangyiwen on 2020/11/16.
//

#ifndef CLEETCODE_TWOSUM_H
#define CLEETCODE_TWOSUM_H

#include<vector>
#include<map>
#include<algorithm>
#include <iostream>

/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 *
 *
 *
 * 一个map 放序号和数字
 * 从头到尾看另一个在map中吗
 *
 * 查找用hash表比较快
 *
 *
 */


class twoSum {
public:
    std::vector<int> Solution(std::vector<int>& nums, int target) {
        std::vector<int > result(2, -1);
        std::map<int, int > cont;
        for (int i = 0; i < nums.size(); ++i) {
            cont.insert(std::map<int, int>::value_type(nums[i], i));
        }

        for (int j = 0; j < nums.size(); ++j) {
            if ((cont.count(target - nums[j])) > 0 && (cont[target - nums[j]] != j)){
                result[0] = j;
                result[1] = cont[target - nums[j]];
            }
        }

        return result;
    };
};


#endif //CLEETCODE_TWOSUM_H
