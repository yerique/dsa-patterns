//gfg_DFS of Graph

class Solution {
public:
    void doDfs(vector<vector<int>>& adj, int node, vector<int> &res, vector<bool> &vis){
        res.push_back(node);
        vis[node] = true;
        vector<int> neighbourList = adj[node];
        for(int i = 0; i < neighbourList.size(); i++){
            int neighbour = neighbourList[i];
            if(vis[neighbour] == false){
                doDfs(adj, neighbour, res, vis);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> res;
        vector<bool> vis(n, false);
        doDfs(adj, 0, res, vis);
        return res;
    }
};