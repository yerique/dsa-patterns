//581. Shortest Unsorted Continuous Subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = -1;
        int run_max = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] >= run_max){
                run_max = nums[i];
            }else{
                end = i;
            }
        }
        int run_min = nums[n-1];
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] <= run_min){
                run_min = nums[i];
            }else{
                start = i;
            }
        }
        return (end == -1) ? 0 : end - start + 1;
    }
};
