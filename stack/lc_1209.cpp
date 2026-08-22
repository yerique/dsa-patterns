//1209. Remove All Adjacent Duplicates in String II

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({s[i], 1});
                continue;
            }
            if(!st.empty() && s[i] != st.top().first){
                st.push({s[i], 1});
                continue;
            }
            if(st.top().second < k - 1){
                pair<char, int> c = st.top();
                st.pop();
                st.push({c.first, c.second + 1});
                continue;
            }
            st.pop();
        }
        string str = "";
        while(!st.empty()){
            pair<char, int> p = st.top();
            st.pop();
            while(p.second--){
                str.push_back(p.first);
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
