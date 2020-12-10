#include <iostream>
#include <vector>
#include "headers/twoSum.h"
#include "headers/addTwoNumbers.h"
#include "headers/lengthOfLongestSubstring.h"
#include "headers/findMedianSortedArrays.h"
#include "headers/longestPalindrome.h"
#include "headers/convert.h"
#include "headers/reverse.h"
#include "headers/myAtoi.h"
#include "headers/isPalindrome.h"
#include "headers/isMatch.h"
#include "headers/maxArea.h"
#include "headers/intToRoman.h"
#include "headers/romanToInt.h"
#include "headers/longestCommonPrefix.h"
#include "headers/threeSum.h"
#include "headers/threeSumClosest.h"
#include "headers/letterCombinations.h"
#include "headers/fourSum.h"
#include "headers/removeNthFromEnd.h"
#include "headers/isValid.h"
#include "headers/mergeTwoLists.h"
#include "headers/generateParenthesis.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    twoSum twosumm = twoSum();
//    std::vector<int> nums = {11, 7, 15, 2};
//    int target = 13;
//    std::vector<int> result = twosumm.Solution(nums, target);
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << " ";
//    }


//    addTwoNumbers addtwonumbers = addTwoNumbers();
//    ListNode *result;
//
//    ListNode *l1 = new ListNode(1);
//    ListNode *l2 = new ListNode(4, l1);
//    ListNode *l3 = new ListNode(2, l2);
//
//    ListNode *r1 = new ListNode(9);
//    ListNode *r2 = new ListNode(9, r1);
//    ListNode *r3 = new ListNode(9, r2);
//
//    result = addtwonumbers.Solution(l3, r3);


//    while (result != NULL) {
//        std::cout << result->val << " ";
//        result = result->next;
//    }


//    lengthOfLongestSubstring l = lengthOfLongestSubstring();
//    std::string s = "abcabcbb";
//    std::cout << l.Solution(s);

//    findMedianSortedArrays f = findMedianSortedArrays();
//    std::vector<int> nums1 = {1, 2};
//    std::vector<int> nums2 = {3, 4};
//    double s = f.Solution(nums1, nums2);
//    std::cout<< s;

//    longestPalindrome l = longestPalindrome();
//    std::string s = l.Solution("babad");
//    std::cout<< s;


//    convert c = convert();
//    std::string s = c.Solution("LEETCODEISHIRING", 4);
//    std::cout<< s;


//    reverse r = reverse();
//    int c = r.Solution(-2147483648);
//    std::cout<< c;

//    myAtoi m = myAtoi();
//    int res = m.Solution("42");
//    int i = (0)? INT_MAX : INT_MIN;
//    std::cout<< i;;

//    isPalindrome p = isPalindrome();
//    if (p.Solution(99))
//        std::cout<< "True";
//    else
//        std::cout<< "False";

//    isMatch i = isMatch();
//    std::cout<< i.Solution("aaa", "a*a");

//    maxArea m = maxArea();
//    std::vector<int > ss = {1,8,6,2,5,4,8,3,7};
//    std::cout<< m.Solution(ss);

//    intToRoman t = intToRoman();
//    std::cout<< t.Solution(1994);

//    romanToInt r = romanToInt();
//    std::cout<< r.Solution("MCMXCIV");

//    longestCommonPrefix l = longestCommonPrefix();
//    std::vector<std::string>s({"flower","flow","flight"});
//    std::cout<< l.Solution(s);

//    threeSum t = threeSum();
//    std::vector<std::vector<int>> result =  t.Solution(std::vector<int >({1, 2, 3}));
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            std::cout << result[i][j] << " ";
//        }
//        std::cout << "\n";
//    }

//    threeSumClosest t = threeSumClosest();
//    std::vector<int>  nums = {1,1,1,0};
//    std::cout<< t.Solution(nums,  -100);


//    letterCombinations l = letterCombinations();
//    std::vector<std::string> resilt = l.Solution("23");
//    for (int i = 0; i < resilt.size(); ++i) {
//        std::cout<< resilt[i] << " ";
//    }


//    fourSum f = fourSum();
//    std::vector<int>  nums = {-3,-1,0,2,4,5};
//    std::vector<std::vector<int>> result = f.Solution(nums, 0);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            std::cout<< result[i][j] << " ";
//        }
//        std::cout<< "\n";
//    }

//    removeNthFromEnd r = removeNthFromEnd();
//    ListNode *head = nullptr;
//    while (head) {
//        std::cout << head->val << " ";
//        head = head->next;
//    }


//    isValid s = isValid();
//    std::cout<< s.Solution("}");

//    mergeTwoLists m = mergeTwoLists();
//    auto *l1 = new ListNode(4);
//    auto *l2 = new ListNode(2, l1);
//    auto *l3 = new ListNode(1, l2);
//
//    auto *r1 = new ListNode(4);
//    auto *r2 = new ListNode(3, r1);
//    auto *r3 = new ListNode(1, r2);
//
//    auto l = m.Solution(l3, r3);
//    while (l){
//        std::cout<< l->val<< " ";
//        l = l->next;
//    }

    generateParenthesis g = generateParenthesis();
    auto ans = g.Solution(9);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << "\n";
    }

//    std::cout<< INT32_MAX<< " "<< INT32_MIN;
//    std::cout<< INT_MAX<< " "<< INT_MIN;
//    std::cout<< -2e31 << " "<< 2e31 - 1;


    return 0;
}