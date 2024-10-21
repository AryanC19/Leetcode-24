class Solution {
public:
    
    
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int c = 0;
    ListNode *res = new ListNode(0);
    ListNode *curr = res;
    while (l1 || l2 || c)
    {

        int d1 = l1 ? l1->val : NULL;
        int d2 = l2 ? l2->val : NULL;
        int sum = d1 + d2 + c;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        c = sum / 10;
    }

    return res->next;
}

};
