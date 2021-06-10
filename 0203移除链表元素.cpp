/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 生成新的头结点指向链表
        ListNode *newHead = new ListNode(0, head);
        // 使用链表类型指针p 指向新的头结点
        ListNode *p = newHead;
        while (p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        return newHead->next;
    }
};