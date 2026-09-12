//gfg_Dijkstra Algorithm

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            adjList[s].push_back({d, wt});
            adjList[d].push_back({s, wt});
        }
        vector<int> dis(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dis[src] = 0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d > dis[node]) continue;
            for(auto pair : adjList[node]){
                int neighbour = pair.first;
                int wt = pair.second;
                int newDis = d + wt;
                if(newDis < dis[neighbour]){
                    dis[neighbour] = newDis;
                    pq.push({newDis, neighbour});
                }
            }
        }
        return dis;
    }
};
