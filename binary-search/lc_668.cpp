//668. Kth Smallest Number in Multiplication Table

class Solution {
public:
    int minEqElements(int m, int n, int guess){
        int row = m; int col = 1;
        int count = 0;
        while(row >= 0 && col <= n){
            if(row * col > guess){
                row--;
            }else{
                count += row;
                col++;
            }
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            int ans = minEqElements(m, n, guess);
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
