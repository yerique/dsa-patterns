//713. Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int count = 0;
        int mul = 1;

        for (int high = 0; high < n; high++) {
            mul = mul * nums[high];

            while (mul >= k && low <= high) {
                mul = mul / (nums[low]);
                low++;
            }
            int len = high - low + 1;
            count = count + len;
        }
        return count;
    }
};
