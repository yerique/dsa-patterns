//23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct cmp {
    bool operator()(const ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < n; i++){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(!pq.empty()){
            ListNode* min = pq.top();
            pq.pop();
            if(min->next != nullptr){
                pq.push(min->next);
            }
            if(head == nullptr){
                head = min;  //for returning at end
                tail = min;  //for adding new nodes(minimum ones) later
            }else{
                tail->next = min;
                tail = min;
            }
        }
        return head;
    }
};
