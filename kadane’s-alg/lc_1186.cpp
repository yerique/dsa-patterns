//1186. Maximum Subarray Sum with One Deletion

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDelSum = arr[0];
        int oneDelSum = INT_MAX;
        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            int prevNoDelSum = noDelSum;
            int prevOneDelSum = oneDelSum;

            noDelSum = max(prevNoDelSum + arr[i], arr[i]);

            int v;
            if(prevOneDelSum == INT_MAX) {
                v = arr[i];
            } else {
                v = prevOneDelSum + arr[i];
            }

            oneDelSum = max(v, prevNoDelSum);
            ans = max(ans, max(noDelSum, oneDelSum));
        }
        return ans;
    }
};
