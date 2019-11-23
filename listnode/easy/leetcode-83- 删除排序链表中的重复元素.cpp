//方法1，辅助链表添加
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode dummy = ListNode(-1);  //  创建栈空间对象即可。
        ListNode* prev = &dummy;   // 注意这里需要取地址&
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
//方法2，直接修改

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = head;   // 注意这里需要取地址&
        while (prev != NULL && prev->next != NULL){
            if (prev->val == prev->next->val){
                prev->next = prev->next->next;
            }
            else{
                prev = prev->next;
            }
        }
        return head;
    }
};
