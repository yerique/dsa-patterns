//347. Top K Frequent Elements

struct cmp{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b){
        if(a.first != b.first) return (a.first > b.first);
        return(a.second > b.second);
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> elTofreq;
        for(int i = 0; i < n; i++){
            elTofreq[nums[i]]++;
        }
        cmp comp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto i: elTofreq){
            int el = i.first;
            int freq = i.second;
            pair<int, int> curr = {freq, el};
            if(pq.size() < k){
                pq.push(curr);
                continue;
            }
            if(comp(pq.top(), curr)){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
