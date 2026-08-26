//153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0; int high = n - 1;
        int res = 0;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] > nums[n - 1]){ //belongs to PART-II
                low = guess + 1;
            }else {                    // belongs to PART-I (to see monotonicity)
                res = guess;
                high = guess - 1;
            }
        }
        return nums[res];
    }
};