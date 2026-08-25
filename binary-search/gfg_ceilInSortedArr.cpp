//gfg_Ceil in a Sorted Array

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ceilIdx = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(arr[guess] >= x){
                ceilIdx = guess;
                high = guess - 1;
            }else {
                low = low + 1;
            }

        }
        return ceilIdx;
    }
};