//62. Unique Paths

//dp-tabu
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;
        for(int j = 0; j <= n; j++){
            dp[m][j] = 0;
        }
        for(int i = 0; i <= m; i++){
            dp[i][n] = 0;
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n -1 ; j>= 0; j--){
                if(i == m-1 && j == n-1)  continue;
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};

//dp-memo of this
 class Solution {
 public:
     int rec(int m, int n, int i, int j, vector<vector<int>>& dp){
         if(i == m - 1 && j == n - 1){
             return dp[i][j] = 1;
         }
         if(i < 0 || i >= m || j < 0 || j >= n){
             return dp[i][j] = 0;
         }
         if(dp[i][j] != -1) return dp[i][j];
         return dp[i][j] = rec(m, n, i, j+1, dp) + rec(m, n, i+1, j, dp);
     }
     int uniquePaths(int m, int n) {
         vector<vector<int>>dp (m+1, vector<int>(n+1, -1));
         return rec(m, n, 0, 0, dp);
     }
 };

//recursion required for this prob.
 class Solution {
 public:
     int rec(int m, int n, int i, int j){
         if(i == m - 1 && j == n - 1){
             return 1;
         }
         if(i < 0 || i >= m || j < 0 || j >= n){
             return 0;
         }
         return rec(m, n, i, j+1) + rec(m, n, i+1, j);
     }
     int uniquePaths(int m, int n) {
         return rec(m, n, 0, 0);
     }
 };
