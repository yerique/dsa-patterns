//Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int k = 1;
        int count = 1;
        while (j<nums.size()){
            if(nums[j] == nums[j-1]){
                count++;
                if(count>2){
                    j++;
                    continue;
                }
                nums[i+1] = nums[j];
                i++;
                k++;
                j++;
                continue;
            }
            count = 1;
            nums[i+1] = nums[j];
            i++;
            k++;
            j++;
        }
        return k;
    }
};

//2nd way
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int k = 1;
        int count = 1;
        while (j<nums.size()){
            if(nums[j] == nums[j-1]){
                count++;
                if(count>2){
                    j++;
                    continue;
                }
                nums[i+1] = nums[j];
                i++;
                k++;
                j++;
                continue;
            }
            count = 1;
            nums[i+1] = nums[j];
            i++;
            k++;
            j++;
        }
        return k;
    }
};