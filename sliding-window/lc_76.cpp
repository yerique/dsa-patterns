//76. Minimum Window Substring

class Solution {
public:
    bool match(vector<int>&have, vector<int>&need){
        for (int i = 0; i < 256; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(n > m) {
            return "";
        }

        int low = 0;
        vector<int> have (256, 0);
        vector<int> need (256, 0);
        int min_len = INT_MAX;
        int start = 0;

        for (int i = 0; i < n; i++) {
            need[t[i]]++;
        }

        for (int high = 0; high < m; high++) {
            have[s[high]]++;

            while (match(have, need)) {
                int window_len = high - low + 1;
                if (window_len < min_len) {
                    min_len = window_len;
                    start = low;

                }

                have[s[low]]--;
                low++;
            }
        }
        return (min_len == INT_MAX) ? "" : s.substr(start, min_len);
    }
};