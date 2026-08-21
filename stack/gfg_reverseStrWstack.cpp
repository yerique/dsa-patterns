//gfg_Reverse Using Stack

class Solution {
public:
    string reverse(const string& S) {
        int n = S.size();
        stack<char> rev;
        string res;
        for(int i = 0; i < n; i++) {
            rev.push(S[i]);
        }
        while(!rev.empty()) {
            char c = rev.top();
            rev.pop();
            res.push_back(c);
        }
        return res;
    }
};