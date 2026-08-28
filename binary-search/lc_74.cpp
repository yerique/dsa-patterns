//74. Search a 2D Matrix

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
