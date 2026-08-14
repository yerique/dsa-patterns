//1004. Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        vector<int> binC(2,0);
        int ans = INT_MIN;
        for (int high = 0; high < n; high++) {
            binC[nums[high]]++;
            int len = high - low + 1;
            int noOf0 = len - binC[1];

            while (noOf0 > k) {
                binC[nums[low]]--;
                low++;
                len = high - low + 1;
                noOf0 = len - binC[1];
            }

            ans = max(len, ans);
        }
        return ans;
    }
};
