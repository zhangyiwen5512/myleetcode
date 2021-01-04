from solutions import twoSum
from solutions import addTwoNumbers
from solutions import lengthOfLongestSubstring
from solutions import findMedianSortedArrays
from solutions import longestPalindrome
from solutions import convert
from solutions import reverse
from solutions import myAtoi
from solutions import isPalindrome
from solutions import isMatch
from solutions import maxArea
from solutions import intToRoman
from solutions import romanToInt
from solutions import longestCommonPrefix
from solutions import threeSum
from solutions import threeSumClosest
from solutions import letterCombinations
from solutions import fourSum
from solutions import removeNthFromEnd
from solutions import isValid
from solutions import mergeTwoLists
from solutions import generateParenthesis
from solutions import mergeKLists
from solutions import swapPairs
from solutions import reverseKGroup
from solutions import removeDuplicates
from solutions import removeElement
from solutions import strStr
from solutions import divide
from solutions import findSubstring
from solutions import nextPermutation
from solutions import longestValidParentheses
from solutions import search
from solutions import searchRange

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# s = twoSum.Solution()
# print(s.twoSum([3, 3], 6))

# s = addTwoNumbers.Solution()
# ListNode = addTwoNumbers.ListNode
# l1 = ListNode(1)
# l2 = ListNode(4, l1)
# l3 = ListNode(2, l2)
#
# r1 = ListNode(9)
# r2 = ListNode(9, r1)
# r3 = ListNode(9, r2)
#
# l = s.addTwoNumbers(l3, r3)
#
# while l != None:
#     print(l.val)
#     l = l.next

# l = lengthOfLongestSubstring.Solution()
# s = "abcabcbb"
# print(l.lengthOfLongestSubstring(s))

# f = findMedianSortedArrays.Solution()
# l1 = [1,2]
# l2 = [3, 4]
# print(f.findMedianSortedArrays(l1, l2))

# l = longestPalindrome.Solution()
# s = l.longestPalindrome("ab")
# print(s)

# c = convert.Solution()
# s = c.convert("A", 2)
# print(s)

# r = reverse.Solution()
# c = r.reverse(-1534236469)
# print(c)

# m = myAtoi.Solution()
# print(m.myAtoi("42"))

# p = isPalindrome.Solution()
# print(p.isPalindrome(2**31 - 1))

# i = isMatch.Solution()
# print(i.isMatch("a", '0'))


# m = maxArea.Solution()
# print(m.maxArea([1,8,6,2,5,4,8,3,7]))

# t = intToRoman.Solution()
# print(t.intToRoman(1994))

# r = romanToInt.Solution()
# print(r.romanToInt("MCMXCIV"))


# l = longestCommonPrefix.Solution()
# print(l.longestCommonPrefix(["reflower","flow","flight"]))

# t = threeSum.Solution()
# print(t.threeSum([-1, 0, 1, 2, -1, -4]))

# t = threeSumClosest.Solution()
# print(t.threeSumClosest([1,1,1,0], -100))

# l = letterCombinations.Solution()
# print(l.letterCombinations("23"))

# f = fourSum.Solution()
# print(f.fourSum([-3,-1,0,2,4,5], 0))

# r = removeNthFromEnd.Solution()
# l1 = ListNode(1)
# l2 = ListNode(2, l1)
# l3 = ListNode(3, l2)
#
#
# r2 = ListNode(4, l3)
# r3 = ListNode(5, r2)
# l = r.removeNthFromEnd(r3, 0)
# while l:
#     print(l.val)
#     l = l.next


# i = isValid.Solution()
# print(i.isValid(" ] "))

# m = mergeTwoLists.Solution()
# l1 = ListNode(4)
# l2 = ListNode(2, l1)
# l3 = ListNode(1, l2)
#
# r1 = ListNode(4)
# r2 = ListNode(3, r1)
# r3 = ListNode(1, r2)
# l = m.mergeTwoLists(l3, r3)
#
# while l:
#     print(l.val)
#     l = l.next


# g = generateParenthesis.Solution()
# print(g.generateParenthesis(4))
# "(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]

# m = mergeKLists.Solution()
# l1 = ListNode(5)
# l2 = ListNode(4, l1)
# l3 = ListNode(1, l2)
#
# r1 = ListNode(4)
# r2 = ListNode(3, r1)
# r3 = ListNode(1, r2)
#
# h1 = ListNode(6)
# h2 = ListNode(2, h1)
#
# l = [l3, r3, h2]
#
# ans = m.mergeKLists([None, h1])
# while ans:
#     print(ans.val)
#     ans = ans.next


# s = swapPairs.Solution()
# r1 = ListNode(4)
# r2 = ListNode(3, r1)
# r3 = ListNode(2, r2)
# r4 = ListNode(1, r3)
# r5 = ListNode(0, r4)
# ans = s.swapPairs(r3)
# # ans = r4
# while ans:
#     print(ans.val)
#     ans = ans.next


# r = reverseKGroup.Solution()
# r0 = ListNode(6)
# r1 = ListNode(5, r0)
# r2 = ListNode(4, r1)
# r3 = ListNode(3, r2)
# r4 = ListNode(2, r3)
# r5 = ListNode(1, r4)
#
# ans = r.reverseKGroup(r5, 6)
# while ans:
#     print(ans.val)
#     ans = ans.next

# r = removeDuplicates.Solution()
# nums = [1,1,1]
# ans = r.removeDuplicates(nums)
# for i in range(ans):
#     print(nums[i])

# r = removeElement.Solution()
# nums = [2]
# ans = r.removeElement(nums, 2)
# for i in range(ans):
#     print(nums[i])

# s = strStr.Solution()
# print(s.strStr("", "aaa"))

# -2147483648
# -1
# d = divide.Solution()
# print(d.divide(-1, 1))

#"barfoofoobarthefoobarman"
#["bar","foo","the"]
# "wordgoodgoodgoodbestword"
# ["word","good","best","good"]
# f = findSubstring.Solution()
# print(f.findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"]))


# n = nextPermutation.Solution()
# print(n.nextPermutation([3,2,1]))


# l = longestValidParentheses.Solution()
# print(l.longestValidParentheses(")()())"))

# s = search.Solution()
# print(s.search([4,5,6,7,0,1,3], 2))

s = searchRange.Solution()
print(s.searchRange([5,7,7,8,8,10], 6))