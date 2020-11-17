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
  *
  *
  *
  *
  */



class addTwoNumbers {
public:
    ListNode* Solution(ListNode* l1, ListNode* l2) {

    }
};


#endif //CLEETCODE_ADDTWONUMBERS_H