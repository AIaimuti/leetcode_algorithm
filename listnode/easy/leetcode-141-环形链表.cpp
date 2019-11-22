//哈希表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set <ListNode*> hash;
        while (head){
            if (hash.find(head) != hash.end()){
                return true;
            }
            else{
                hash.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

//快慢指针

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow) {
                    return true;
                }
            }
        return false;
    }
};
