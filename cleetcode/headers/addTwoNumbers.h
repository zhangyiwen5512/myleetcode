//
// Created by zhangyiwen on 2020/11/17.
//

#ifndef CLEETCODE_ADDTWONUMBERS_H
#define CLEETCODE_ADDTWONUMBERS_H


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

};

/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 * 相同位上的存在则相加，带上进位，若长度不够则给一个空listnode， 依次进入下一位的计算
 * 判断最后一个进位是否要取1，构造新listnode
 *
 *
 *
 *
 *
 *
 *
 *
 */



class addTwoNumbers {
public:
    ListNode* Solution(ListNode* l1, ListNode* l2) {
        int addone = 0;
        ListNode *result = new ListNode();
        ListNode *current = result;
        while (l1 || l2) {
            int temp = 0;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;

            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }

            temp += addone;
            addone = temp / 10;
            current->next = new ListNode(temp % 10);
            current = current->next;
        }

        if (addone) {
            current->next = new ListNode(1);
        }
        return result->next;
    }
};


#endif //CLEETCODE_ADDTWONUMBERS_H
