//300. Longest Increasing Subsequence

//via binary search - most optimal soln, but do go through dp soln of this, see below.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tail; //this is requied lis we want make so, to make  it that we need to make the ending of this smallest possible so that it can be extended as much as possible
        for(int x : nums){
            int low  = 0;
            int high = tail.size();
            while(low < high){
                int guess = (low + high)/2;
                if(tail[guess] < x){
                    low = guess + 1;
                }else{
                    high = guess; //[low mid) mid can be an answer a typical low bound bs case where this is norm not mid - 1
                }
            }
            if(low == tail.size()){
                tail.push_back(x);
            }else{
                tail[low] = x;
            }
        }
        return tail.size();
    }
};

//trick-tabulation(a different way to think) ans = max val of (max length lis ending at each i)
 class Solution {
 public:
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<int>maxLenLisEndAti(n);
         for(int i = 0; i < n; i++){
             maxLenLisEndAti[i] = 1;
             for(int j = 0; j < i; j++){
                 if(nums[j] < nums[i]){
                     maxLenLisEndAti[i] = max(maxLenLisEndAti[i], maxLenLisEndAti[j] + 1);
                 }
             }
         }
         int ans = *max_element(maxLenLisEndAti.begin(), maxLenLisEndAti.end());
         return ans;
     }
 };

//space optimization of dp-tabu
 class Solution {
 public:
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<int>curr(n+1, 0);
         vector<int>next(n+1, 0); // bc is taken care of here
         for(int i = n-1; i >= 0; i--){
             for(int j = -1; j < n; j++){
                 if(j == -1 || nums[i] > nums[j]){
                     curr[j+1] = max(1 + next[i+1], next[j+1]);
                 }else{
                     curr[j+1] = next[j+1];
                 }
             }
             next = curr;
         }
         return next[0];
     }
 };

//dp-tab conversion
 class Solution {
 public:
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
         for(int j = 0; j <=n; j++){
             dp[n][j] = 0;
         }
         for(int i = n-1; i >=0; i--){
             for(int j = -1; j<n; j++){
                 if(j == -1 || nums[i] > nums[j]){
                     dp[i][j+1] = max(1 + dp[i+1][i+1], dp[i+1][j+1]);
                 }else{
                     dp[i][j+1] = dp[i+1][j+1];
                 }
             }
         }
         return dp[0][0];
     }
 };



//dp-memo of lis
 class Solution {
 public:
     int doDp( vector<int>& nums, int n, int i, int prev,vector<vector<int>>& dp){
         if(i == n) return 0;
         if(dp[i][prev+1] != -1) return dp[i][prev+1]; //storing in prev+1 to avoid segment error and its our dairy we can do what we want.
         if(prev == -1 || nums[i] > nums[prev]){
             int c1 = 1 + doDp(nums, n, i+1, i, dp);
             int c2 = doDp(nums, n, i+1, prev, dp);
             return dp[i][prev+1] = max(c1, c2);
         }
         return dp[i][prev+1] = doDp(nums, n, i+1, prev, dp);
     }
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
         int prev = -1;
         return doDp(nums, n, 0, prev, dp);
     }
 };


// rec for lis: ofc tle hai isme
 class Solution {
 public:
     int rec(vector<int>& nums, int n, int i, int prev){
         if (i == n) return 0;
         if(prev == -1 || nums[i] > nums[prev]){
             int c1 = 1 + rec(nums, n, i+1, i);
             int c2 = rec(nums, n, i+1, prev);
             return max(c1, c2);
         }
         return rec(nums, n, i+1, prev);
     }
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         int prev = -1;
         return rec(nums, n, 0, prev);

     }
 };
