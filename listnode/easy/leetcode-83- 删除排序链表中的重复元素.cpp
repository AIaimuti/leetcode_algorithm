
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode dummy = ListNode(-1);  
        ListNode* prev = &dummy;   
        while (head){
            while (head->next && head->val == head->next->val){
                head = head->next;
            }
            prev->next = head;
            prev = prev->next;
            head = head->next;
        }
        return dummy.next;
    }
};
