//34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;
        int last = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] < target){
                low = guess + 1;
            }
            else if(nums[guess] > target){
                high = guess - 1;
            }else{
                first = guess;
                high = guess - 1;
            }
        }
        low = 0;
        high = n - 1;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] < target){
                low = guess + 1;
            }
            else if(nums[guess] > target){
                high = guess - 1;
            }else{
                last = guess;
                low = guess + 1;
            }
        }
        return {first, last};
    }
};
