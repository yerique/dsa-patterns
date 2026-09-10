//gfg_Undirected Graph Cycle

class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>& adjList, int node, int parent, vector<bool>& vis){
        vis[node] = 1;
        for(int neighbour : adjList[node]){
            if(vis[neighbour] && neighbour != parent){
                cycle = true;
            }
            if(!vis[neighbour]){
                dfs(adjList, neighbour, node, vis);
            }
        }
        return;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }

        vector<bool> vis(V, 0);
        for(int node = 0; node < V; node++){
            if(!vis[node]){
                dfs(adjList, node, -1, vis);
            }
        }
        return cycle;
    }
};