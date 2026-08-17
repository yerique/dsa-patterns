//1749. Maximum Absolute Sum of Any Subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return abs(nums[0]);
        }
        int maxPosSum = nums[0];
        int minNegsSum = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            maxPosSum = max(maxPosSum + nums[i], nums[i]);
            minNegsSum = min(minNegsSum + nums[i], nums[i]);
            ans = max(ans, max(abs(minNegsSum), abs(maxPosSum)));
        }
        return ans;
    }
};
