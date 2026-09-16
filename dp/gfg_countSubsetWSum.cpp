//gfg_Count Subsets with Sum

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(target + 1));
        for(int j = 0; j <= target; j++){
            dp[n][j] = 0;
            if(j == 0) dp[n][j] = 1;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= target; j++){
                if(arr[i] > j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-arr[i]] + dp[i+1][j];
                }
            }

        }
        return dp[0][target];
    }
};
