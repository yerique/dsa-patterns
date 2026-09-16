//gfg_Target Sum

class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if((total_sum + target) % 2 != 0 || abs(target) > total_sum){
            return 0;
        }
        int sum = (total_sum + target)/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        for(int j = 0; j <= sum; j++){
            dp[n][j] = 0;
            if(j == 0) dp[n][j] = 1;
        }
        for(int i = n -1; i >= 0; i--){
            for(int j = 0; j <= sum; j++){
                if(arr[i] > j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-arr[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
};