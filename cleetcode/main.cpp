#include <iostream>
#include<vector>
#include "headers/twoSum.h"
#include "headers/addTwoNumbers.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    twoSum twosumm = twoSum();
    std::vector<int> nums = {11, 7, 15, 2};
    int target = 13;
    std::vector<int> result = twosumm.Solution(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

//    addTwoNumbers addtwonumbers = addTwoNumbers();
//    ListNode* result;
//    while (result->next != NULL){
//        std::cout << result->val << " ";
//        result = result->next;
//
//    }



    return 0;
}