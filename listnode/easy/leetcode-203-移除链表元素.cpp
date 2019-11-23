class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode* dummy =new ListNode(-1);  
        dummy->next = head;
        ListNode* p = dummy;  
        while (head){
            if (head->val == val){
                head = head->next;
                p->next = head;
            }
            else{
                p = p->next;
                head = head->next;
            }
        }
        
        return dummy->next;
    }
};
