//152. Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int bestMaxProd = nums[0];
        int bestMinProd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int prevBestMaxProd = bestMaxProd;
            int prevBestMinProd = bestMinProd;
            int v1 = prevBestMaxProd * nums[i];
            int v2 = prevBestMinProd * nums[i];
            int v3 = nums[i];
            bestMaxProd = max(v1, max(v2, v3));
            bestMinProd = min(v1, min(v2, v3));

            ans = max(bestMaxProd, ans);
        }
        return ans;

    }
};