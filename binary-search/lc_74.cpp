//74. Search a 2D Matrix

//by two BS passes (better soln below)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //colmns
        int low = 0; int high = m - 1;
        int row = 0;
        while(low <= high){
            int guess = (low + high)/2;
            if(matrix[guess][0] <= target){
                row = guess;
                low = guess + 1;
            }else{
                high = guess - 1;
            }
        }
        low = 0; high = n - 1;
        while(low <= high){
            int guess = (low + high)/2;
            if(matrix[row][guess] == target){
                return true;
            }
            else if(matrix[row][guess] < target){
                low = guess + 1;
            }else{
                high = guess - 1;
            }
        }
        return false;
    }
};

//better soln -> one BS passes.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //colmns
        int low = 0;
        int high = n * m - 1;
        while(low <= high){
            int guess = (low + high)/2;
            int row = guess / n;
            int col = guess % n;
            int el = matrix[row][col];
            if(el == target){
                return true;
            }
            else if(el < target){
                low = guess + 1;
            }
            else{
                high = guess - 1;
            }
        }
        return false;
    }
};