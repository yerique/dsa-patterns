//gfg_Graph Adjacency List Traversal

class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i<edges.size(); i++){
            int src = edges[i].first;
            int dest = edges[i].second;
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        return adjList;

    }
};
