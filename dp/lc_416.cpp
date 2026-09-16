//416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if(total_sum % 2 != 0) return false;
        int sum = total_sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        for(int j = 0; j <= sum; j++){
            dp[n][j] = 0;
            if(j == 0) dp[n][j] = 1;
        }
        for(int i = n -1; i>= 0; i--){
            for(int j = 0; j <= sum; j++){
                if(nums[i] > j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-nums[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
};
