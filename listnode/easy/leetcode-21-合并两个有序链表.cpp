//方法1，利用辅助空间
#include<vector>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        vector <int> s;
        while (l1 && l2){
            if (l1->val < l2->val){
                s.push_back(l1->val);
                l1 = l1->next;
            }
            else if (l1->val == l2->val){
                s.push_back(l1->val);
                s.push_back(l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                s.push_back(l2->val);
                l2 = l2->next;
            }
        }
        while (l1){
            s.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s.push_back(l2->val);
            l2 = l2->next;
        } 
        ListNode* l = new ListNode(s[0]);
        ListNode* head = l;

        for (int i = 1; i < s.size(); i++){
            ListNode* newNode = new ListNode(0);
            newNode->val = s[i];
            l->next = newNode;
            l = l->next;
        }
    return head;
    }
};

//使用新链表排序添加

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(-1);  //  创建栈空间对象即可。
        ListNode* prev = &dummy;   // 注意这里需要取地址&
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 != NULL ? l1 : l2;
        return dummy.next;
    }
};
