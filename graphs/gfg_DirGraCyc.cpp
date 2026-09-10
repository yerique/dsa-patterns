//gfg_Directed Graph Cycle

class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>& adjList, int node, vector<bool>& vis, vector<bool>& path){
        vis[node] = 1;
        path[node] = 1;
        for(int neighbour : adjList[node]){
            if(vis[neighbour] && path[neighbour]){
                cycle = true;
            }
            else if(!vis[neighbour]){
                dfs(adjList, neighbour, vis, path);
            }
        }
        path[node] = 0;
        return;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
        }
        vector<bool> vis(V, 0);
        vector<bool> path(V, 0);
        for(int node = 0; node < V; node++){
            if(!vis[node]){
                dfs(adjList, node, vis, path);
            }
        }
        return cycle;
    }
};