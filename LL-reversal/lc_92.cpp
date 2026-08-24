//92. Reverse Linked List II

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left == right){
            return head;
        }
        ListNode* before = nullptr;
        ListNode* start = head;
        int pos = 1;
        while(pos < left){
            before = start;
            start = start->next;
            pos++;
            continue;
        }
        ListNode* curr = start;
        ListNode* prev = nullptr;
        int nodes = right - left + 1;
        while(nodes--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        start->next = curr;
        if(before){
            before->next = prev;
            return head;
        }
        return prev;
        //works also but above oneis better says gemini
        // if(left == 1){
        //     return prev;
        // }
        // before->next = prev;
        // return head;
    }
};
