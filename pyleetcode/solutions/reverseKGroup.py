class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 给你这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
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
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head

        if k == 1:
            return head

        first = head
        last = head

        n = k - 1
        while n > 0 and head.next:
            head = head.next
            n -= 1

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
            n = k - 1
            while n > 0 and first.next:
                first = first.next
                n -= 1

            temp = first.next

            if n == 0:
                tail = reversr(first, last, tail)

            first = temp
            last = temp

            if temp == None:
                return head
