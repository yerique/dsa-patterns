//785. Is Graph Bipartite?

class Solution {
public:
    bool bipar = true;
    void dfs(vector<vector<int>>& graph,  int node, int c, vector<int>& color){
        color[node] = c;
        for(int neighbour : graph[node]){
            if(color[neighbour] == c){
                bipar = false;
                return;
            }
            else if(color[neighbour] == -1){
                dfs(graph, neighbour, 1-c, color); //if neighbour in uncolout we gotta colout it with other colout 1 or 0
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int node = 0; node < n; node++){
            if(color[node] == -1){
                dfs(graph, node, 0, color); // we wanna colour node with 0
            }
        }
        return bipar;
    }
};
