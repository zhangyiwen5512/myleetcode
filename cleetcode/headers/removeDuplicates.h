//
// Created by zhangyiwen on 2020/12/13.
//

#ifndef CLEETCODE_REMOVEDUPLICATES_H
#define CLEETCODE_REMOVEDUPLICATES_H
/**
 * * 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 *
 * 给定数组 nums = [1,1,2],
 * 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 * 你不需要考虑数组中超出新长度后面的元素
 *
 * 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 * 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 * 你不需要考虑数组中超出新长度后面的元素。
 *
 * 为什么返回数值是整数，但输出的答案是数组呢?
 * 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 * 你可以想象内部操作如下:
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 * // 在函数里修改输入数组对于调用者是可见的
 * // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 * for (int i = 0; i < len; i++)
 *      print(nums[i]);
 *
 *
 * 循环i表示当前数字，stop表示经过的数字，stop==n推出
 *
 * 去掉和current相同的数字，
 * 当相同时duplicate ++；删除current + 1到duplicate 并插入后面
 *
 *
 * nums[j] != nums[i] 不重复，跳过覆盖当前i
 * nums[j] == nums[i] 重复，j++
 *
 */


class removeDuplicates {
public:
    int Solution(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;








//        int n = nums.size();
//        if (n == 0)
//            return 0;
//        if (n == 1)
//            return 1;
//        int stop = 0;
//        int i = 0;
//
//        while (i < n){
//            stop += Duplicates(nums, i, n);
//            i += 1;
//
//            if (stop == n)
//                break;
//        }
//
//        return i;
    }
    int Duplicates(std::vector<int>&nums, int current, int n){
        int duplicate = current + 1;
        while (duplicate < n and nums[current] == nums[duplicate])
            duplicate += 1;

        if (current + 1 != duplicate)
            for (int i = current + 1; i < duplicate; ++i) {
                nums.erase(nums.begin() + current);
                nums.push_back(nums[current]);
            }


        return duplicate - current;

    }


};


#endif //CLEETCODE_REMOVEDUPLICATES_H
