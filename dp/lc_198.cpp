//198. House Robber

class Solution {
public:
    int doDp(vector<int>& nums, int n, int i, int f, vector<vector<int>>& dp){
        if(i == n) { //base case
            return 0;
        }
        //seeign something which we have seem before
        if (dp[i][f] != -1){
            return dp[i][f];
        }
        //seeing something new
        //with no freewil you just have to move forward and skip this house(got not choice)
        if(f == 0){
            return dp[i][f] = doDp(nums, n, i+1, 1, dp);
        }
        //now if you have choice do have two of them
        int c1 = nums[i] + doDp(nums, n, i+1, 0, dp);
        int c2 = doDp(nums, n, i+1, 1, dp);
        return dp[i][f] = max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return doDp(nums, n, 0, 1, dp);
    }
};
