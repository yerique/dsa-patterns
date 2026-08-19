//525. Contiguous Array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int zeroes = 0;
        int max_len = 0;
        unordered_map<int, int> findReqDiff;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                ones++;
            }
            else {
                zeroes++;
            }
            int diff = ones - zeroes;
            if(diff == 0){
                max_len = max(max_len, i+1);
                continue;
            }
            if(findReqDiff.find(diff) == findReqDiff.end()) {
                findReqDiff[diff] = i;
            }
            else {
                int len = i - findReqDiff[diff];
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};