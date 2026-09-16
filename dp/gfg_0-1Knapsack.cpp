//gfg_0 - 1 Knapsack Problem

//via dp memo
class Solution {
public:
    int doDp(vector<int> &val, vector<int> &wt, int i, int n, int cap, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(dp[i][cap] != -1){
            return dp[i][cap];
        }
        if(wt[i] > cap){
            return dp[i][cap] = doDp(val, wt, i+1, n, cap, dp);
        }
        int c1 = val[i] + doDp(val, wt, i+1, n, cap-wt[i], dp);
        int c2 = doDp(val, wt, i+1, n, cap, dp);
        return dp[i][cap] = max(c1, c2);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1)); //w+1 cuz 0-indexing okay, we want to include max available weight allowed as well in the coloumn
        return doDp(val, wt, 0, n, W, dp);
    }
};

//via dp tabulation:
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n+1, vector<int>(W+1));
        for(int bcCol = 0; bcCol <= W; bcCol++){
            dp[n][bcCol] = 0;
        }
        for(int row = n-1; row >= 0; row--){ //represent i the item
            for (int col = W; col >= 0; col--){ //represent the capaciy when item is in sack...could've done both ways actually doesnt matter
                if(wt[row] > col){
                    dp[row][col] = dp[row+1][col];
                }
                else{
                    int c1 = val[row] + dp[row+1][col - wt[row]];
                    int c2 = dp[row+1][col];
                    dp[row][col] = max(c1, c2);
                }
            }
        }
        return dp[0][W];
    }
};