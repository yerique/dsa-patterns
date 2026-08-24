//25. Reverse Nodes in k-Group

class Solution {
public:
    void reverse(ListNode* left, int size){
        ListNode* curr = left;
        ListNode* prev = nullptr;
        while(size--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* res = nullptr;
        ListNode* right;
        int size = k; //size of nodes to be reversed
        while(true){
            right = left;
            for(int i = 0; i < size - 1; i++){
                if(right == nullptr){
                    break;
                }
                right = right->next;
            }
            if(right){ // left right part mil gya ek to
                ListNode* nextLeft = right->next;
                reverse(left, size);
                if(prevLeft){
                    prevLeft->next = right;
                }
                prevLeft = left;
                if(res == nullptr){
                    res = right;
                }
                left = nextLeft;
            }else{ //no right anymore
                if(prevLeft){
                    prevLeft->next = left;
                }
                if(res == nullptr){
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};
