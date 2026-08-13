//424. Longest Repeating Character Replacement

class Solution {
public:
    int find(vector<int> &a) {
        int max_c = -1;
        for (int i = 0; i < 256; i++) {
            max_c = max(max_c, a[i]);
        }
        return max_c;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int max_str = INT_MIN;
        vector<int> f(256, 0);

        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int maxEl = find(f);
            int diff = len - maxEl;

            while (diff > k) {
                f[s[low]]--;
                low++;
                len--;
                maxEl = find(f);
                diff = len - maxEl;
            }
            max_str = max(len, max_str);
        }
        return max_str;
    }
};