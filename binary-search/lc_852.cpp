//852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0; int high = n - 2; // could use n-1 if l < h in while btw, also no need to handle this cuz it is strictly a mountain array but it is good practise.
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(arr[guess] > arr[guess + 1]){ //downhill
                res = guess;        //store cuz maybe this
                high = guess - 1;   //discard the down-slope
            }
            else {                  //uphill
                low = guess + 1;     //search in right
            }
        }
        return res;
    }
};