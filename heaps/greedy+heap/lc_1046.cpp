//1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for (auto i : stones){
            pq.push(i);
        }
        while(!pq.empty()){
            int s1 = pq.top(); pq.pop();
            if(pq.empty()){
                return s1;
            }
            int s2 = pq.top(); pq.pop();
            s1 = s1 - s2;
            if(s1 > 0){
                pq.push(s1);
            }
        }
        return 0;
    }
};