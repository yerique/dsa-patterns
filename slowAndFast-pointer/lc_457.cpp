//457. Circular Array Loop

class Solution {
public:
    int getNext(vector<int>& nums, int i){
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;
            int slow = i;
            int fast = getNext(nums, i);
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNext(nums, fast)] > 0){
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
                if(slow == fast){
                    if(slow == getNext(nums, slow)){
                        break;
                    }
                    return true;
                }
            }
            //optimization
            int curr = i;
            int val = nums[i];
            while(val * nums[curr] > 0){
                int nex = getNext(nums, curr);
                nums[curr] = 0;
                curr = nex;
            }
        }
        return false;
    }
};
