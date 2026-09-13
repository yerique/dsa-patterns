//gfg_Minimum Spanning Tree

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            adjList[s].push_back({d, wt});
            adjList[d].push_back({s, wt});
        }
        int sum =  0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0,0});
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto [neighbour, wt] : adjList[node]){
                if(vis[neighbour] == 0){
                    pq.push({wt, neighbour});
                }
            }
        }
        return sum;
    }
};