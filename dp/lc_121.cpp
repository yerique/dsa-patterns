//121. Best Time to Buy and Sell Stock

//dp-tabu - the real deal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int k = 2;
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        for(int j = 0; j <= k; j++){
            dp[n][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(j == 2){
                    dp[i][j] = max(dp[i+1][j-1] - prices[i], dp[i+1][j]);
                }else{
                    dp[i][j] = max(dp[i+1][j-1] + prices[i], dp[i+1][j]);
                }
            }
        }
        return dp[0][k];
    }
};

//dp-memo
 class Solution {
 public:
     int doDp(vector<int>& prices, int n, int i, int k, vector<vector<int>>& dp){
         if(i == n) return 0;
         if(k == 0) return 0;
         if(dp[i][k] != -1) return dp[i][k];
         if(k == 2){
             int c1 = doDp(prices, n, i+1, k-1, dp) - prices[i];
             int c2 = doDp(prices, n, i+1, k, dp);
             return dp[i][k] = max(c1, c2);
         }else{
             int c1 = doDp(prices, n, i+1, k-1, dp) + prices[i];
             int c2 = doDp(prices, n, i+1, k, dp);
             return dp[i][k] = max(c1, c2);
         }
     }
     int maxProfit(vector<int>& prices) {
         int n = prices.size();
         if(n == 1) return 0;
         int k = 2;
         vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
         int gain = doDp(prices, n, 0, k, dp);
         return gain;
     }
 };

//rec for the question
 class Solution {
 public:
     int rec(vector<int>& prices, int n, int i, int k){ //k tells what we got
         if(i == n) return 0;
         if(k == 0) return 0;
         if(k == 2){ //either you can buy or leave it
             int c1 = rec(prices, n, i+1, k - 1) - prices[i]; //and buy means you are losin that much
             int c2 = rec(prices, n, i+1, k); //lets just no buy today
             return max(c1, c2);
         }else{ //k = 1 either can only sell or leave it
             int c1 = rec(prices, n, i+1, k-1) + prices[i];//setting mean you get much
             int c2 = rec(prices, n, i+1, k);
             return max(c1, c2);
         }
     }
     int maxProfit(vector<int>& prices) {
         int n = prices.size();
         if(n == 1) return 0;
         int k = 2; //in our world 1buy and 1sell is 2 transaction
         int gain = rec(prices, n, 0, k);
         return gain;
     }
 };
