//gfg_0 - 1 Knapsack Problem

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
