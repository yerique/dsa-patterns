//974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int, int> findSumModk;
        findSumModk[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) {
                rem = rem + k;
            }
            int freq = findSumModk[rem];
            count += freq;
            findSumModk[rem]++;
        }
        return count;
    }
};