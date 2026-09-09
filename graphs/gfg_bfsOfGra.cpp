//gfg_BFS of Graph

class Solution {
public:
    void doBfs(vector<vector<int>> &adj, int node, vector<int> &res, vector<bool> &vis){
        queue<int> que;
        que.push(node);
        vis[node] = true;
        while(!que.empty()){
            int newNode = que.front();
            que.pop();
            res.push_back(newNode);
            vector<int> neighbour_list = adj[newNode];
            for(int i = 0; i < neighbour_list.size(); i++){
                int neighbour = neighbour_list[i];
                if(vis[neighbour] == false){
                    que.push(neighbour_list[i]);
                    vis[neighbour] = true;
                }
            }
        }
        return;
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> res;
        vector<bool> vis(n, false);
        doBfs(adj, 0, res, vis);
        return res;

    }
};
