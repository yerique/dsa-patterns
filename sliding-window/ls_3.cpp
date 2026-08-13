//3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0 ;
        int max_str = 0;
        unordered_map<char, int> f;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            while (f.size() < len) {
                f[s[low]]--;

                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
                len--;
            }
            max_str = max(len, max_str);
        }
        return max_str;
    }
};
