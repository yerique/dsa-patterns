//692. Top K Frequent Words

struct cmp{
    bool operator()(const pair<int,string>&a, const pair<int,string>&b){
        if(a.first != b.first) return (a.first > b.first);
        return (a.second < b.second);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> strTofreq;
        for(int i = 0; i < n; i++){
            strTofreq[words[i]]++;
        }
        cmp comp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for( auto i : strTofreq){
            string str = i.first;
            int freq = i.second;
            pair<int, string> curr = {freq, str};
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
        vector<string> res;
        while(!pq.empty()){
            string str = pq.top().second;
            res.push_back(str);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
