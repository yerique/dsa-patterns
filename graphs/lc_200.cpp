//200. Number of Islands

class Solution {
public:
    bool isValid(int i, int j, int rows, int cols){
        if(i < 0 || i >= rows || j < 0 || j >= cols){
            return false;
        }
        return true;
    }
    vector<int> xDir = {-1, 1, 0, 0};
    vector<int> yDir = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int i , int j, int n, int m, vector<vector<bool>> &vis){
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int row = i + xDir[k];
            int col = j + yDir[k];
            if(isValid(row, col, n, m) && grid[row][col] == '1' && vis[row][col] == 0){
                dfs(grid, row, col, n, m, vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int i,j;
        vector<vector<bool>> vis(n);
        for(int i = 0; i < n; i++){
            vector<bool> t(m, 0);
            vis[i] = t;
        }
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid, i, j, n, m, vis);
                    res++;
                }
            }
        }
        return res;
    }
};
