//918. Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int maxSum = nums[0];
        int currMin = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for(int i = 1; i < n; i++) {

            totalSum = totalSum + nums[i];
            //case-I-> for in-between
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);

            //case -II-> for ends
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);
        }

        if(maxSum < 0) {
            return maxSum;
        }
        int ans1 = maxSum;
        int ans2 = totalSum - minSum;
        int res = max(ans1, ans2);
        return res;

    }
};
