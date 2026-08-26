//33. Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0; int high = n - 1;
        while (low <= high){
            int g = (low + high)/2;
            if(nums[g] == target) return g;
            if(nums[g] > nums[n -1]){ // part - 1
                if(target > nums[g]){
                    low = g + 1;
                }else{
                    if(target < nums[0]){
                        low = g + 1;
                    }else{
                        high = g - 1;
                    }
                }
            }else{ // part - 2
                if(target < nums[g]){
                    high = g - 1;
                }else{
                    if(target > nums[n-1]){
                        high = g - 1;
                    }else{
                        low = g + 1;
                    }
                }
            }
        }
        return -1;
    }
};
