//哈希表

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> hash;
        while (headA){
            hash.insert(headA);
            headA = headA->next;
        }
        while (headB){
            if (hash.find(headB) != hash.end()){
                return headB;
            }
            else {
                headB = headB->next;
            }
        }
        return headB;
    }
};
//裁剪法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* countA = headA;
        ListNode* countB = headB;
        int A = 0;
        int B = 0;
        while (countA){
            A++;
            countA = countA->next;
        }
        while (countB){
            B++;
            countB = countB->next;
        }
        while (A < B){
            headB = headB->next;
            B--;
        }
        while (A > B){
            headA = headA->next;
            A--;
        }
        while (A == B){
            if (headA == headB){
                return headA;
            }
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL; 
    }
};
