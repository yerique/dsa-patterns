//122. Best Time to Buy and Sell Stock II

//dp-tabu
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>>dp(n+1, vector<int>(k+1));
        for(int j = 0; j <= k; j++){
            dp[n][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = n -1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(j == 2){
                    dp[i][j] = max(dp[i+1][j-1] - prices[i], dp[i+1][j]);
                }else{
                    dp[i][j] = max(dp[i+1][2] + prices[i], dp[i+1][j]);
                }
            }
        }
        return dp[0][k];
    }
};
//this question is just and extenstion of part i do check that for rec->dp-memo->dp-tabu
