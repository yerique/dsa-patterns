//410. Split Array Largest Sum

class Solution {
public:
    bool possible(const vector<int>& nums, int k, int guess) {
        int subarrays = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= guess) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
                if (subarrays > k) {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;
        int low = 0; int high = 0;
        for(int i = 0; i < n; i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(possible(nums, k, guess)){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};