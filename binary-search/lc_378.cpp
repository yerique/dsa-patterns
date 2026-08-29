//378. Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    int minEqElement(vector<vector<int>>&matrix, int n, int m, int guess){
        int row = n - 1; int col = 0;
        int count = 0;
        while(row >= 0 && col < m){
            int el = matrix[row][col];
            if(el > guess){
                row--;
            }else{
                count += row + 1;
                col++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //colmns
        int low = INT_MAX; int high = INT_MIN;
        for(int i = 0; i < n; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            int ans = minEqElement(matrix, n, m, guess);
            if(ans < k){
                low = guess + 1;
            }else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};