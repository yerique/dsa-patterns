//gfg_Number of Connected Components

class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int vir, vector<bool>& vis){
        vis[vir] = 1;
        vector<int> adjacents = adjList[vir];
        for(int i = 0; i < adjacents.size(); i++){
            int connectedVir = adjacents[i];
            if(!vis[connectedVir]){
                dfs(adjList, connectedVir, vis);
            }
        }
        return;
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        // now adjcacency list is made
        int comp = 0;
        vector<bool> vis(V, 0);
        for(int vir = 0; vir < V; vir++){
            if(!vis[vir]){
                dfs(adjList, vir, vis);
                comp++;
            }
        }
        return comp;

    }
};
