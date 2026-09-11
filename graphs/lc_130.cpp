//130. Surrounded Regions

//my first thought ->  spreading -> bfs so i did this soln can be done via dfs as well see below
class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> safe;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    if(board[i][j] == 'O'){
                        safe.push({i, j});
                        board[i][j] = '#';
                    }
                }
            }
        }
        int xDir[4] = {-1, 1, 0, 0};
        int yDir[4] = {0, 0, -1, 1};
        while(!safe.empty()){
            pair<int, int> p = safe.front();
            safe.pop();
            int r = p.first;
            int c = p.second;
            for(int k = 0; k < 4; k++){
                int row = r + xDir[k];
                int col = c + yDir[k];
                if(isVal(row, col, n, m) && board[row][col] == 'O'){
                    safe.push({row, col});
                    board[row][col] = '#';
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//via dfs

class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    int xDir[4] = {-1, 1, 0, 0};
    int yDir[4] = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        grid[i][j] = '#';
        for(int k = 0; k < 4; k++){
            int row = i + xDir[k];
            int col = j + yDir[k];
            if(isVal(row, col, n ,m) && grid[row][col] == 'O'){
                dfs(grid, row, col, n, m);
            }
        }
        return;
    }
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(grid[i][j] == 'O'){
                        dfs(grid, i, j, n, m);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '#'){
                    grid[i][j] = 'O';
                }else{
                    grid[i][j] = 'X';
                }
            }
        }

    }
};