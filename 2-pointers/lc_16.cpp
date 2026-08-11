//16. 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res_sum = 0;
        int min_diff = INT_MAX;

        for ( int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r ) {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(sum - target);

                if ( diff < min_diff) {
                    min_diff = diff;
                    res_sum = sum;
                }

                if ( sum == target) {
                    return res_sum = sum;
                }

                else if (sum < target) {
                    l++;
                }

                else {
                    r--;
                }

            }

        }
        return res_sum;
    }
};