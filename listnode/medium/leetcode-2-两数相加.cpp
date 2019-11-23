class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        int val = 0;
        int x = 0;
        while(val || l1 || l2) {
            x = (val + (l1?l1->val:0) + (l2?l2->val:0))%10;
            val = (val + (l1?l1->val:0) + (l2?l2->val:0))/10;
            p->next = new ListNode(x);
            p = p->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return temp->next;

    }
};
