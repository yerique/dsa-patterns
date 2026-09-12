//743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int >>> adjList(n);
        for(int i = 0; i < times.size(); i++){
            int sr = times[i][0];
            int dest = times[i][1];
            int t = times[i][2];
            adjList[sr-1].push_back({dest-1, t});
        }
        vector<int> timeTo(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src = k - 1;
        pq.push({0, src});
        timeTo[src] = 0;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(time > timeTo[node]) continue;
            for(auto [neighbour, t] : adjList[node]){
                int newTime = time + t;
                if(newTime < timeTo[neighbour]){
                    timeTo[neighbour] = newTime;
                    pq.push({newTime, neighbour});
                }
            }
        }
        int ans = *max_element(timeTo.begin(), timeTo.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};
