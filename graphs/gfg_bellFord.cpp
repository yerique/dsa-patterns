//gfg_Bellman Ford

class Solution {
public:
    bool relaxation(vector<vector<int>>& edges, vector<int>& res){
        bool relaxed = false;
        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];
            int newWt = res[src] + wt;
            if(res[src] != 1e8 && newWt < res[dest]){
                res[dest] = newWt;
                relaxed = true;
            }
        }
        return relaxed;
    }
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> res(V, 1e8);
        res[src] = 0;
        for (int i = 0; i < V - 1; i++){
            relaxation(edges, res);
        }
        if(relaxation(edges, res)) return {-1};
        return res;
    }
};

