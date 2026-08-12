//209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(high < n) {
            sum += nums[high];

            while(sum >= target){
                int len = high - low + 1;
                ans = min(len, ans);
                low++;
                sum = sum - nums[low-1];
            }

            high++;
        }
        return (ans == INT_MAX) ? 0 :ans;
    }
};