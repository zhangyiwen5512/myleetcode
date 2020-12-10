//
// Created by zhangyiwen on 2020/12/7.
//

#ifndef CLEETCODE_REMOVENTHFROMEND_H
#define CLEETCODE_REMOVENTHFROMEND_H
/*
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 给定的 n 保证是有效的。
 *
 * 你能尝试使用一趟扫描实现吗？
 *
 * 两个指针相差距离为n
*/
//struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class removeNthFromEnd {
public:
    ListNode* Solution(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        int step = 0;
        while (p1->next){
            p1 = p1->next;
            if (step >= n)
                p2 = p2->next;

            ++step;
        }

        if (step + 1 == n)
            return head->next;

        p2->next = p2->next->next;

        return head;
    }
};


#endif //CLEETCODE_REMOVENTHFROMEND_H
