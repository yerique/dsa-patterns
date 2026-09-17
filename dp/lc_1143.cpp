//1143. Longest Common Subsequence

//dp-tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int j = 0; j <= m; j++){
            dp[n][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][m] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0 ; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};

//dp-memo did:
 class Solution {
 public:
     int doDp(string text1, string text2, int n, int m, int i, int j, vector<vector<int>>& dp){
         if(i == n || j == m) return 0;
         if(dp[i][j] != -1) return dp[i][j];
         if(text1[i] == text2[j]){
             return dp[i][j] = 1 + doDp(text1, text2, n, m, i+1, j+1, dp);
         }else{
             int c1 = doDp(text1, text2, n, m, i+1, j, dp);
             int c2 = doDp(text1, text2, n, m, i, j+1, dp);
             return dp[i][j] = max(c1, c2);
         }
     }
     int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();
         int i,j;
         vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
         return doDp(text1, text2, n, m, 0, 0, dp);

     }
 };

//only the rec fo the question:
 class Solution {
 public:
     int rec(string text1, string text2, int n, int m, int i, int j){
         if(i == n || j == m) return 0;
         if(text1[i] == text2[j]) return 1 + rec(text1, text2, n, m, i+1, j+1);
         int c1 = rec(text1, text2, n, m, i+1, j);
         int c2 = rec(text1, text2, n, m, i, j+1);
         return max(c1, c2);
     }
     int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();
         int i = 0, j = 0;
         return rec(text1, text2, n, m, i, j);
     }
 };
