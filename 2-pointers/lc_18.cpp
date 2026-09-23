//18. 4Sum


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i]== nums[i-1]) continue;
            for(int l = i + 1; l < n; l++){
                if(l>i+1 && nums[l]== nums[l-1]) continue;
                int m = l+1;
                int r = n - 1;
                long long modiTar = (long long)target - (nums[i] + nums[l]);
                while(m < r){
                    int sum = nums[m] + nums[r];
                    if(sum == modiTar){
                        res.push_back({nums[i], nums[l], nums[m], nums[r]});
                        m++;
                        r--;
                        while(m < r && nums[m] == nums[m-1]){
                            m++;
                        }
                        while(r > m && nums[r] == nums[r+1]){
                            r--;
                        }
                    }else if(sum > modiTar){
                        r--;
                    }else{
                        m++;
                    }
                }
            }
        }
        return res;
    }
};