//Minimum Sum Subarray

class Solution {
public:
    int minSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int minSum = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int v1 = minSum + arr[i];
            int v2 = arr[i];
            minSum = min(v1, v2);
            ans = min(minSum, ans);
        }
        return ans;
    }
};