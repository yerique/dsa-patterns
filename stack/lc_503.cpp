//503. Next Greater Element II

//1st way --> preload (1st pass) then check nextgreat(2nd pass)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[n-1]);
        vector<int> res(n);
        for(int i = n-1; i >= 0; i--){
            st.push(nums[i]);
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};

//2nd-way --  2*n - 1 --> 0 (common approach for circular array) with one pass only both things happens.
// and we also don't have unnecessary memory allocation of redundant element in stack(only utiliy element remains jinka kaam ayega).

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = 2 * n -1; i >= 0; i--){
            int curr = i % n;
            while(!st.empty() && st.top() <= nums[curr]){
                st.pop();
            }
            if(i < n){
                if(st.empty()){
                    res[i] = -1;
                } else{
                    res[i] = st.top();
                }
            }
            st.push(nums[curr]);
        }

        return res;
    }
};
