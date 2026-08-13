//Longest Substring with K Uniques

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int low = 0;
        int max_len = INT_MIN;
        unordered_map<char, int > f;

        for (int high = 0 ; high < n; high++) {
            f[s[high]]++;

            while (f.size() > k) {
                f[s[low]]--;

                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }

                low++;
            }

            if (f.size() == k){
                int len = high - low + 1;
                max_len = max(len, max_len);
            }
        }
        return (max_len == INT_MIN)? -1 : max_len;
    }
};
