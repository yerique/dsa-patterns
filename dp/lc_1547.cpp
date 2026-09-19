//1547. Minimum Cost to Cut a Stick

//don't overemphasies on this one it is a question almost out of interview scope (not for OA, nothing is out of scope for that now tbh)

//dp-tabu(very complicated to understand the flow of filling dp but yeah it is a very hard one)
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int>tweaked;
        tweaked.push_back(0);
        for(int i = 0; i < cuts.size(); i++){
            tweaked.push_back(cuts[i]);
        }
        tweaked.push_back(n);
        int s = tweaked.size();
        sort(tweaked.begin(), tweaked.end());
        vector<vector<int>>dp(s+1, vector<int>(s+1));
        int start = 1 ; int end = s-2;
        for(int i  = end; i >= start; i--){
            for(int j = i; j <= end; j++){
                int res = INT_MAX;
                for(int k = i; k <= j; k++){
                    int cost = tweaked[j+1] - tweaked[i-1];
                    int r = cost + dp[i][k-1] + dp[k+1][j];
                    res = min(res, r);
                }
                dp[i][j] = res;
            }
        }
        return dp[start][end];
    }
};

//dp-memo
 class Solution {
 public:
     int doDp(vector<int>& tweaked, int i, int j, vector<vector<int>>& dp){
         if(i>j) return 0;
         int res = INT_MAX;
         if(dp[i][j] != -1) return dp[i][j];
         for(int k = i; k <= j; k++){
             int cost = tweaked[j+1] - tweaked[i-1];
             int r = cost + doDp(tweaked, i, k-1, dp) + doDp(tweaked, k+1 , j, dp);
             res = min(res, r);
         }
         return dp[i][j]= res;
     }
     int minCost(int n, vector<int>& cuts) {
         vector<int>tweaked;
         tweaked.push_back(0);
         for(int i = 0; i < cuts.size(); i++){
             tweaked.push_back(cuts[i]);
         }
         tweaked.push_back(n);
         int s = tweaked.size();
         sort(tweaked.begin(), tweaked.end());
         vector<vector<int>>dp(s+1, vector<int>(s+1, -1));
         return doDp(tweaked, 1, s-2, dp);

     }
 };


//recursion of the question-> actually most imp for this one the core logic is here
 class Solution {
 public:
     int solve(vector<int>& tweaked, int i, int j){
         if( i > j) return 0; //[i,j] is range essentially so that is impossible
         int res = INT_MAX;
         for(int k = i; k <= j; k++){
             int cost = tweaked[j+1] - tweaked[i-1];
             int r = cost + solve(tweaked, i, k-1) + solve(tweaked, k+1 , j);
             res = min(res, r);
         }
         return res;
     }
     int minCost(int n, vector<int>& cuts) {
         vector<int>tweaked;
         tweaked.push_back(0);
         for(int i = 0; i < cuts.size(); i++){
             tweaked.push_back(cuts[i]);
         }
         tweaked.push_back(n); // all this tweaking was quick fix (ad-hoc way to make the approach to work in start as well)
         int s = tweaked.size();
         sort(tweaked.begin(), tweaked.end()); //vimp entire logic depends on it
         return solve(tweaked, 1, s-2); //s is size -> ending idx s-1 and our og cuts last element is siting at 1 before i.e., s-2;
     }
 };