//438. Find All Anagrams in a String

class Solution {
public:
    bool match(vector<int>s_map, vector<int>p_map) {
        for(int i = 0; i<26; i++) {
            if (s_map[i]!= p_map[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> s_map(26, 0);
        int n = s.size();
        vector<int> p_map(26, 0);
        int m = p.size();
        if (m > n) {
            return res;
        }
        for(int i = 0; i < m; i++) {
            p_map[p[i] - 'a']++;
        }
        int low = 0;
        int high = m - 1;


        for(int i = low; i < m; i++){
            s_map[s[i] - 'a']++;
        }

        while (low <= n-m && high < n ){
            if (match(s_map, p_map)) {
                res.push_back(low);
            }
            s_map[s[low] - 'a']--;
            low++;
            high++;
            if(high >= n) {
                break;
            }
            s_map[s[high] - 'a']++;

        }
        return res;
    }
};