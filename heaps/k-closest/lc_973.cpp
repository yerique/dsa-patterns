//973. K Closest Points to Origin


struct cmp{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b){
        // if(a.first != b.first) // dont need in this question but GP
        if(a.first != b.first)
            return (a.first < b.first); // high d on top-> max heap of distance
        return (a.second < b.second); // if d same high idx on top -> not req.
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, int>> disAIdxPair;
        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            disAIdxPair.push_back({d, i});
        }
        cmp comp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto el : disAIdxPair){
            // int d = el.first;
            if(pq.size() < k){
                pq.push(el);
                continue;
            }
            if(comp(pq.top(), el)){
                continue;
            }
            pq.pop();
            pq.push(el);
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            int idx = pq.top().second;
            res.push_back(points[idx]);
            pq.pop();
        }
        return res;
    }
};
