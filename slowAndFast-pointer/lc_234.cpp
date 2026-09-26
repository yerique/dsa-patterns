//234. Palindrome Linked List

class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* curr = node;
        while (curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = reverse(slow);
        ListNode* h1 = head;
        while(h2){
            if(h2->val != h1->val){
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};