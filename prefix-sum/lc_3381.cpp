//(extra)3381. Maximum Subarray Sum With Length Divisible by K
//can be optimized we use vector instead of hashmap

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = LLONG_MIN;
        long long curr_sum = 0;
        unordered_map<long long, long long> min_prefix;
        min_prefix[0] = 0;

        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            int curr_len = i + 1 ;
            int len_rem = curr_len % k;

            if(min_prefix.find(len_rem) != min_prefix.end()) {
                max_sum = max(max_sum, curr_sum - min_prefix[len_rem]);
                min_prefix[len_rem] = min(min_prefix[len_rem], curr_sum);
            } else {
                min_prefix[len_rem] = curr_sum;
            }

        }
        return max_sum;
    }
};
