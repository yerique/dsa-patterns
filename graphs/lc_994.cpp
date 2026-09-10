//994. Rotting Oranges

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
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> que;
        int fresh = 0; int time = 0; int i,j;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                    grid[i][j] = -2;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        while(!que.empty() && fresh > 0){
            time++;
            int s = que.size();
            while(s--){
                pair<int, int> p = que.front();
                que.pop();
                int r = p.first;
                int c = p.second;
                for(int k = 0; k < 4; k++){
                    int row = r + xDir[k];
                    int col = c + yDir[k];
                    if(isVal(row, col, n, m) && grid[row][col] == 1){
                        que.push({row, col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            }
        }
        return (fresh > 0) ? -1 : time;
    }
};