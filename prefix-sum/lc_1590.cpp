//(extra)1590. Make Sum Divisible by P
//this one took me many hours just because can't seem to get
// int needed = curr_rem - target_rem;
           // if(needed < 0) {
               // needed += p;
            //}
// this logic just now know that it is alwat between 0----j---i---n-1.
// we are at i and asking for a j our req ans (is between j+1 to i) is most cat-II prefix problems.

//Below is AI saying the same:
//Key Takeaway:
// In Category-II prefix problems: Array structure is [0 ... j ... i ... n-1].
// We stand at index 'i' (current prefix) and look back for an earlier anchor 'j'
// such that the slice nums[j+1 ... i] satisfies the condition.
// Derivation of 'needed':
// 1. Goal:  (Prefix[i] - Prefix[j]) % p == target_rem
// 2. Mod:   (curr_rem - needed) % p    == target_rem
// 3. Solve: curr_rem - needed          =  target_rem
//           needed                     =  curr_rem - target_rem
// 4. C++:   If (needed < 0), add p to wrap it back to [0, p - 1]:
//           int needed = curr_rem - target_rem;
//           if (needed < 0) needed += p;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target_rem = 0;
        int min_len = n;
        for(int i = 0; i < n; i++) {
            target_rem = (target_rem + nums[i]) % p;
        }

        if(target_rem == 0){
            return 0;
        }

        int curr_rem = 0;
        unordered_map<int, int> prefix_mod_index;
        prefix_mod_index[0] = -1;

        for(int i = 0; i < n; i++) {
            curr_rem = (curr_rem + nums[i]) % p;
            if (nums[i] == target_rem) {
                return 1;
            }
            int needed = curr_rem - target_rem;
            if(needed < 0) {
                needed += p;
            }
            if(prefix_mod_index.find(needed) != prefix_mod_index.end()) {
                int len = i - prefix_mod_index[needed];
                min_len = min(min_len, len);
            }
            prefix_mod_index[curr_rem] = i;
        }
        return (min_len == n) ? -1 : min_len;
    }
};