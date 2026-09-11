//1091. Shortest Path in Binary Matrix

class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    int xDir[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
    int yDir[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); //cols
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        if(n == 1 && m == 1) return 1;
        queue<pair<pair<int, int>, int>> que;
        que.push({{0,0}, 0});
        grid[0][0] = 2;
        while(!que.empty()){
            pair<pair<int, int>, int> p = que.front();
            que.pop();
            int i = p.first.first;
            int j = p.first.second;
            int dis = p.second;
            for(int k = 0; k < 8; k++){
                int row = i + xDir[k];
                int col = j + yDir[k];
                if(isVal(row, col, n, m) && grid[row][col] != 2 && grid[row][col] == 0){
                    int newDis = dis + 1;
                    que.push({{row,col}, newDis});
                    grid[row][col] = 2;
                    if(row == n - 1 && col == m - 1){
                        return newDis + 1; //cuz we want no of visited cell/node not danda
                    }
                }
            }
        }
        return -1;
    }
};
