//778. Swim in Rising Water

//via dijkstra
class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    int xDir[4] = {-1, 1, 0, 0};
    int yDir[4] = {0, 0, -1, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1e8));
        priority_queue<pair<int, pair<int, int >>, vector<pair<int, pair<int, int >>>, greater<pair<int, pair<int, int >>>> pq;
        pq.push({grid[0][0], {0,0}});
        res[0][0] = grid[0][0];
        while(!pq.empty()){
            auto [time, cor] = pq.top();
            pq.pop();
            int r = cor.first;
            int c = cor.second;
            if(time > res[r][c]) continue;
            for(int k = 0; k < 4; k++){
                int row = r + xDir[k];
                int col = c + yDir[k];
                if(!isVal(row, col, n, m)) continue;
                int newM = max(time, grid[row][col]);
                if(newM < res[row][col]){
                    pq.push({newM, {row, col}});
                    res[row][col] = newM;
                }
            }
        }
        return res[n-1][m-1];
    }
};

//via binary search + bfs
class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m ) return false;
        return true;
    }
    int xDir[4] = {-1, 1, 0, 0};
    int yDir[4] = {0, 0, -1, 1};
    bool bfs(vector<vector<int>>& grid, int n , int m, int guess){
        if(guess < grid[0][0]) return false;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> que;
        que.push({0,0});
        vis[0][0] = 1;
        while(!que.empty()){
            auto [r, c] = que.front();
            que.pop();
            if(r == n -1 && c == m - 1) return true;
            for(int k = 0; k < 4; k++){
                int row = r + xDir[k];
                int col = c + yDir[k];
                if(isVal(row, col, n, m) && vis[row][col] == 0 && guess >= grid[row][col]){
                    que.push({row, col});
                    vis[row][col] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = grid[0][0];
        for(auto row : grid){
            high = max(high, *max_element(row.begin(), row.end()));
        }
        while(low <= high){
            int guess = (low + high)/2;
            if(bfs(grid, n, m, guess)){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};

//via binary search + dfs
class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m ) return false;
        return true;
    }
    int xDir[4] = {-1, 1, 0, 0};
    int yDir[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& grid, int i, int j, int n , int m, int guess, vector<vector<bool>> &vis, bool &reached){
        vis[i][j] = 1;
        if(i == n-1 && j == m -1 ){
            reached = true;
            return;
        }
        for(int k = 0; k < 4; k++){
            int row = i + xDir[k];
            int col = j + yDir[k];
            if(isVal(row, col, n, m) && vis[row][col] == 0 && guess >= grid[row][col]){
                dfs(grid, row, col, n ,m, guess, vis, reached);
            }
        }
        return;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = grid[0][0];
        for(auto row : grid){
            high = max(high, *max_element(row.begin(), row.end()));
        }
        while(low <= high){
            vector<vector<bool>> vis(n, vector<bool>(m, 0));
            int guess = (low + high)/2;
            bool reached = false;
            if(guess >= grid[0][0]){
                dfs(grid, 0, 0, n, m, guess, vis, reached);
            }
            if(reached){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};