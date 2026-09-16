//gfg_Subset Sum Problem

//via dp-tabulation
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        for(int j = 0; j <= sum; j++){
            dp[n][j] = 0;
        }
        dp[n][0] = 1;
        for(int i = n-1; i>= 0; i--){
            for(int j = 0; j <= sum; j++){
                if(arr[i] > j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-arr[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
};

 //via dp-memo
class Solution {
public:
    bool doDp(vector<int>& arr,int n, int i, int sum, vector<vector<int>>& dp){
        if(i == n){
            return (sum == 0) ? true : false;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(arr[i] > sum){
            return dp[i][sum] = doDp(arr, n, i+1, sum, dp);
        }
        int c1 = doDp(arr, n, i+1, sum - arr[i], dp);
        int c2 = doDp(arr, n, i+1, sum, dp);
        return dp[i][sum] = c1 || c2;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return doDp(arr, n, 0, sum, dp);

    }
};


//this is only the recursion that is needed in the problem
class Solution {
public:
    bool rec(vector<int>& arr, int n, int sum, int i){
        if(i == n){
            return (sum == 0 ) ? true : false;
        }
        if(arr[i] > sum){
            return rec(arr, n, sum, i+1);
        }
        int c1 = rec(arr, n, sum - arr[i], i+1);
        int c2 = rec(arr, n, sum, i+1);
        return c1 || c2;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return rec(arr, n, sum, 0);

    }
};