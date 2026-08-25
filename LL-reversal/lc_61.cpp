//61. Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int n = 1;
        ListNode* last = head;
        while(last->next){
            n++;
            last = last->next;
        }
        k = k % n;
        if(k == 0) return head;
        int count = 1;
        ListNode* t = head;
        while(count != n - k){
            count++;
            t = t->next;
        }
        last -> next = head;
        head = t->next;
        t->next = nullptr;
        return head;
    }
};