//哈希表
//遍历一边使用哈希表储存每个结点，遇到倒数第n个，也就是正数（size - n + 1）的时候跳过

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
//快慢指针
//倒数第n个，也就是正数（size - n + 1）个

//先快指针走n步，慢指针就少走n步，快指针走完size步数时，慢指针走了（size - n）步，慢指针下一个结点即为所需删除的第倒数第n个结点
#include <map>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next && n==1) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n-- && fast) fast=fast->next;
        if(!fast) return head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
