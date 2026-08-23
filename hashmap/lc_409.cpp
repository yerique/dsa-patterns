//409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<char, int> have;
        for(int i = 0; i < n; i++){
            have[s[i]]++;
        }
        for(auto i : have){
            int c = i.second;
            if(c % 2 == 0){
                res += c;
            }
            if(c % 2 != 0){
                res += c -1;
            }
        }
        if(res < n){    //atleast one odd number was left
            return res + 1;
        }
        return res;
    }
};
