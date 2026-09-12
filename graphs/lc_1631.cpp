//1631. Path With Minimum Effort

class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    int xDir[4] = {-1, 1, 0, 0};
    int yDir[4] = {0, 0, -1, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effortMat(n);
        for(int i = 0; i < n; i++){
            vector<int> t(m, INT_MAX);
            effortMat[i] = t;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        effortMat[0][0] = 0;
        while(!pq.empty()){
            auto [effort, cor] = pq.top();
            pq.pop();
            int r = cor.first;
            int c = cor.second;
            if(effort > effortMat[r][c]) continue;
            for(int k = 0; k < 4; k++){
                int row = r + xDir[k];
                int col = c + yDir[k];
                if(!isVal(row, col, n, m)) continue;
                int newEffort = max(effort, abs(heights[r][c] - heights[row][col]));
                if(newEffort < effortMat[row][col]){
                    effortMat[row][col] = newEffort;
                    pq.push({newEffort, {row, col}});
                }
            }
        }
        return effortMat[n-1][m-1];
    }
};