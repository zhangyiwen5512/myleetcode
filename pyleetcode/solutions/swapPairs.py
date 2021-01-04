class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 * 输入：head = []
 * 输出：[]
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 * head为第k个结点
 * first优先走k-1步
 * 用temp存first.next为下一个结点
 * tail =  reversr(first, last, tail)翻转last到first在之间的结点
 *
 * first = temp；last = temp
 * 当temp为空时返回head
 *
 * reversr()逆向链表，返回tail，新的尾部
 * 处理首位
 * tail = last；
 * last.next = first.next；
 * tail.next = first；
 *
 * 处理中间
 * last = last.next；
 * t.next = x；
 * x = t；
 * t = last；
 *
 *
 *
 *
 *
"""


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head

        first = head
        last = head
        n = 2

        k = n - 1
        while k > 0 and head.next:
            head = head.next
            k -= 1

        def reversr(first, last, tail):
            t = last.next
            x = last
            last.next = first.next
            if tail:
                tail.next = first

            tail = x

            last = t
            if not last:
                return tail
            while last != first:
                last = last.next
                t.next = x
                x = t
                t = last

            first.next = x
            return tail

        tail = None
        while True:
            k = n - 1
            while k > 0 and first.next:
                first = first.next
                k -= 1

            temp = first.next

            tail = reversr(first, last, tail)

            first = temp
            last = temp

            if temp == None:
                return head
