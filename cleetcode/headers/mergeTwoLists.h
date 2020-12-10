//
// Created by zhangyiwen on 2020/12/10.
//

#ifndef CLEETCODE_MERGETWOLISTS_H
#define CLEETCODE_MERGETWOLISTS_H

/*
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 *
 * 当l1 l2 都不空时
 * 当l1 < = l2则将l1接入否则将l2接入
 * l.next = l1;l1 = l1.next;l = l.next
 *
 * 将剩余非空列表接入l
 *
 *
 */

class mergeTwoLists {
public:
    ListNode* Solution(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        auto head = l1;
        auto l = head;

        if (l1->val < l2->val) {
            head = l1;
            l = l1;
            l1 = l1->next;
        } else {
            head =l2;
            l = l2;
            l2 = l2->next;
        }

        while (l1 and l2){
            while (l1 && l1->val <= l2->val){
                l->next = l1;
                l1 = l1->next;
                l = l->next;
            }

            if (!l1)
                break;

            while (l2 && l2->val < l1->val){
                l->next = l2;
                l2 = l2->next;
                l = l->next;
            }

        }

        if (l1)
            l->next = l1;
        if (l2)
            l->next = l2;

        return head;
    }
};


#endif //CLEETCODE_MERGETWOLISTS_H
