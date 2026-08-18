//560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int, int> findSumMinusK;
        findSumMinusK[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int freq = findSumMinusK[sum - k];
            count += freq;
            findSumMinusK[sum]++;
        }
        return count;
    }
};
