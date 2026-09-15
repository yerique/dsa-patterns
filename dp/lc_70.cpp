//70. Climbing Stairs

class Solution {
public:
    unordered_map<int, int> dp;
    int doDp(int i, int n){
        if(i == n) return 1;
        if(i > n ) return 0;
        if(dp.find(i) != dp.end()) return dp[i];
        int a1 = doDp(i + 1, n);
        int a2 = doDp(i + 2,n );
        int ans = a1 + a2;
        dp[i] = ans;
        return ans;
    }
    int climbStairs(int n) {
        int i = 0;
        return doDp(i, n);
    }
};

////wth dp tabulation
 class Solution {
 public:
     int climbStairs(int n) {
         vector<int> dp(n+2);
         dp[n] = 1;
         dp[n+1] = 0;
         for(int i = n - 1; i >=0; i--){
             dp[i] = dp[i + 1] + dp[i+2];
         }
         return dp[0];
     }
 };

//via dp tabulation with space optimzation
class Solution {
public:
    int climbStairs(int n) {
        int age = 1;
        int ageAge = 0;
        int ans = 0;
        for(int i = n - 1; i >=0; i--){
            ans = age + ageAge;
            ageAge = age;
            age = ans;
        }
        return ans;
    }
};
