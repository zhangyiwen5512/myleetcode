# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 给定的 n 保证是有效的。
 *
 * 你能尝试使用一趟扫描实现吗？
 * 两个指针相差距离为n
 *
"""


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        p1 = head
        p2 = head
        step = 0
        while p1.next:
            p1 = p1.next
            if step >= n:
                p2 = p2.next

            step += 1

        if step + 1 == n:
            return head.next

        p2.next = p2.next.next

        return head
