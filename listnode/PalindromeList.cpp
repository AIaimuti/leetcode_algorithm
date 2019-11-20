/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//第一种方法，用栈实现
using namespace std;
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        stack <int> s;
        while (A){
        if (s.empty() || A->val != s.top()){
            s.push(A->val);
            A = A->next;
        }
        else {
            s.pop();
            A = A->next;
        }
        }
        return s.empty();
    }
};
