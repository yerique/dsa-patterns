//387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> hm;
        for(int i = 0; i < n; i++){
            hm[s[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(hm[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};