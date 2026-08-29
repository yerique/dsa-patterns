//240. Search a 2D Matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //colmns
        int row = n - 1; int col = 0;
        while(row >= 0 && col < m){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                col++;
            }
            else{
                row--;
            }
        }
        return false;
    }
};
