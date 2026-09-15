//509. Fibonacci Number (via dp)

// we have done this before but that was pure recursion only this is the start of dp.
class Solution {
public:
    unordered_map<int, int >dp;
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        if(dp.find(n) != dp.end()) return dp[n];
        int a1 = fib(n - 1);
        int a2 = fib(n - 2);
        int ans = a1 + a2;
        dp[n] = ans;
        return ans;
    }
};

//via dp tabulation:
 class Solution {
 public:
     int fib(int n) {
         if(n == 0 || n == 1) return n;
         vector<int> dp(n+1);
         dp[0] = 0;
         dp[1] = 1;
         for(int i = 2; i <= n; i++){
             dp[i] = dp[i-1] + dp[i-2];
         }
         return dp[n];
     }
 };

//dp tabulation with optimized space
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        int prevPrev = 0;
        int prev = 1;
        int ans = 0;
        for(int i = 2; i <=n; i++){
            ans = prev + prevPrev;
            prevPrev = prev;
            prev = ans;
        }
        return ans;
    }
};