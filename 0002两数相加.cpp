struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
需明确链表的使用方法
*/ 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int flag = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (l1 || l2)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            sum = a + b + flag;

            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            flag = sum / 10;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (flag == 1)
        {
            tail->next = new ListNode(1);
        }
        return head;
    }
};
