//gfg_Shortest Path in Unweighted Graph

class Solution {
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        if(src == dest) return 0;
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            adjList[s].push_back(d);
            adjList[d].push_back(s);
        }
        vector<int> res(V, -1);
        vector<bool> vis(V, 0);
        queue<pair<int, int>> que;
        que.push({ src,0 });
        vis[src] = 1;
        while(!que.empty()){
            pair<int, int> p = que.front();
            que.pop();
            int node = p.first;
            int dis = p.second;
            res[node] = dis;
            for(int neighbour : adjList[node]){
                if(!vis[neighbour]){
                    que.push({neighbour, dis + 1});
                    vis[neighbour] = 1;
                }
            }
        }
        return res[dest];
    }
};
