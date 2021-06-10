#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
假设链表A长度为a+c，链表B长度为b+c;
在第c个位置相交，则A走过a+c+b且B走过b+c+a时相遇，这时pa==pb;
然后一共A走过a+c+b+c且B走过b+c+a+c，最后c步是一起走
pA:1->2->3->4->5->6->null->9->5->6->null
pB:9->5->6->null->1->2->3->4->5->6->null
*/ 
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb)
        {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};