//53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = maxSum + nums[i];
            int v2 = nums[i];
            maxSum = max(v1, v2);
            ans = max(maxSum, ans);
        }
        return ans;
    }
};