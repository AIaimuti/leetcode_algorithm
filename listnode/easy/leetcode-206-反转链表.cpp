class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode *new_head = NULL;
        while (cur){
            ListNode *temp = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = temp;
        }
        return new_head;
    }
};
