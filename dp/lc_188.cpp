//188. Best Time to Buy and Sell Stock IV

//dp-tabu
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = k * 2;
        vector<vector<int>>dp(n+1, vector<int>(k+1));
        for(int j = 0; j <= k; j++){
            dp[n][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = n -1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(j % 2 == 0){
                    dp[i][j] = max(dp[i+1][j-1] - prices[i], dp[i+1][j]);
                }else{
                    dp[i][j] = max(dp[i+1][j-1] + prices[i], dp[i+1][j]);
                }
            }
        }
        return dp[0][k];
    }
};
//this question is just and extenstion of part i,ii and iii, do check i for rec->dp-memo->dp-tabu