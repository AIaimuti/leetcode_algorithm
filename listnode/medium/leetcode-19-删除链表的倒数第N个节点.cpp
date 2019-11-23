#include <map>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        map <int, ListNode*> hash;
        int i = 1;
        while (head){
            hash[i] = head;
            head = head->next;
            i++;
        }
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        int val = hash.size() - n + 1;
        for (i = 1; i<= hash.size();i++){
            if (i == val){
                i++;
            }
            p->next = hash[i];
            p = p->next;
        }
        return temp->next;
    }
};
