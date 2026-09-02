//gfg_Palindrome String

class Solution {
private:
    bool isPalCheck(string& s, int low, int high) {
        int len = high - low + 1;
        if(len == 0 || len == 1){
            return true;
        }
        if(s[low] != s[high]){
            return false;
        }
        return isPalCheck(s, low + 1, high - 1);
    }
public:
    bool isPalindrome(string&s){
        return isPalCheck(s, 0, s.size() - 1);
    }
};