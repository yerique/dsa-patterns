//724. Find Pivot Index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum - nums[0] == 0) {
            return 0;
        }
        for(int i = 1; i < n; i++) {
            left += nums[i-1];
            int right = sum - left - nums[i];

            if(left == right) {
                return i;
            }
        }
        return -1;
    }
};