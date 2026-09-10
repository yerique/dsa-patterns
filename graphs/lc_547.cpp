//547. Number of Provinces

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, int city, vector<bool>& vis){
        vis[city] = 1;
        for(int neighbour = 0; neighbour < n; neighbour++){
            if(isConnected[city][neighbour] == 1 && !vis[neighbour]){
                dfs(isConnected, n, neighbour, vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); //no. of cities
        int prov = 0;
        vector<bool> vis(n,0);
        for(int city = 0; city < n; city++){
            if(!vis[city]){
                dfs(isConnected, n, city, vis);
                prov++;
            }
        }
        return prov;
    }
};
