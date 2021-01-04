//
// Created by zhangyiwen on 2020/12/12.
//

#ifndef CLEETCODE_REVERSEKGROUP_H
#define CLEETCODE_REVERSEKGROUP_H
#include "addTwoNumbers.h"
/*
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
 */


class reverseKGroup {
public:
    ListNode* Solution(ListNode* head, int k) {
        if (head == nullptr or head->next == nullptr){
            return head;
        }
        if (k == 1)
            return head;

        auto first = head;
        auto last = head;

        auto n = k - 1;
        while (n > 0 and head->next){
            head = head->next;
            n -= 1;
        }

        ListNode* tail = nullptr;
        while (true){
            n = k - 1;
            while (n > 0 and first->next){
                first = first->next;
                n -= 1;
            }

            ListNode* temp = first->next;

            if (n == 0)
                tail =  reversr(first, last, tail);

            first = temp;
            last = temp;

            if (temp == nullptr)
                return head;
        }
    }


    ListNode* reversr(ListNode*& first, ListNode* &last, ListNode*& tail){
        auto t = last->next;
        auto x = last;
        last->next = first->next;
        if (tail)
            tail->next = first;

        tail = x;

        last = t;
        if (!last)
            return tail;
        while (last != first){
            last = last->next;
            t->next = x;
            x = t;
            t = last;
        }

        first->next = x;
        return tail;
    }


};


#endif //CLEETCODE_REVERSEKGROUP_H
