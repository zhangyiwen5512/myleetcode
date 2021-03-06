class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 *
 *
 * 当l1 l2 都不空时
 * 当l1 < = l2则将l1接入否则将l2接入
 * l.next = l1;l1 = l1.next;l = l.next
 *  
 * 将剩余非空列表接入l
 *
 *
"""


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1

        l = ListNode(0, None)
        head = l

        while l1 and l2:
            while l1 and l1.val <= l2.val:
                l.next = l1
                l1 = l1.next
                l = l.next

            if not l1:
                break

            while l2 and l2.val < l1.val:
                l.next = l2
                l2 = l2.next
                l = l.next

        if l1:
            l.next = l1
        if l2:
            l.next = l2

        return head.next
