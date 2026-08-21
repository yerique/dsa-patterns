//496. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        st.push(nums2[n-1]);
        unordered_map<int, int> nextGreat; //using hm for better val retrival
        nextGreat[nums2[n-1]] = -1;
        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                nextGreat[nums2[i]] = -1;
            } else {
                nextGreat[nums2[i]] = st.top(); // item(key) --> nextGreat(val)
            }
            st.push(nums2[i]);
        }
        vector<int>res;
        for(int val: nums1){
            res.push_back(nextGreat[val]);
        }

        return res;
    }
};
