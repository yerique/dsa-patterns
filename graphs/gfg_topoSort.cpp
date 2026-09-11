//gfg_Topological Sort

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        vector<int> indegree(V,0);
        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adjList[src].push_back(dest);
            indegree[dest]++;
        }
        vector<int> res;
        queue<int> que;
        for(int node = 0; node < V; node++){
            if(indegree[node] == 0){
                que.push(node);
            }
        }
        while(!que.empty()){
            int p = que.front();
            que.pop();
            res.push_back(p);
            for(int nighbour: adjList[p]){
                indegree[nighbour]--;
                if(indegree[nighbour] == 0){
                    que.push(nighbour);
                }
            }
        }
        return res;
    }
};
