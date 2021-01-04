from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 输入：lists = [[]]
 * 输出：[]
 *
 * 输入：lists = []
 * 输出：[]
 *
 * 输入：lists = []
 * 输出：[]
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * l和head指向空node
 * 构建小根堆，以每个列表第一个元素
 * 得到这个最小元素n = p.top()
 * l.next = lists[n]
 * lists[n] = lists[n].next放入队列
 * l = l.next
 *
"""


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if lists == []:
            return None

        k = len(lists)

        l = ListNode(0, None)
        head = l

        while True:
            empty = 0
            x = 2 ** 31 - 1
            for i in range(k):
                if not lists[i]:
                    empty += 1
                elif lists[i].val < x:
                    n = i
                    x = lists[i].val

            if empty == k:
                break

            l.next = lists[n]
            lists[n] = lists[n].next
            l = l.next
        return head.next
