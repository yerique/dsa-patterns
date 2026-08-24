//24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* res = nullptr;
        ListNode* right;
        int size = 2; //pair size -> 2
        while(true){
            right = left;
            for(int i = 0; i < size-1; i++){
                if(right == nullptr){
                    break;
                }
                right = right->next;
            }
            if(right){ // left right pair found
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
            }else { //no right now
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