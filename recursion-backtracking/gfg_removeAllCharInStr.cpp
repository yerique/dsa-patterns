//gfg_Remove all occurrences of a character in a string

class Solution {
private:
    void removeChar(string &s, int n, int i, char c, string &res){
        if(i == n){
            return;
        }

        if(s[i] != c){
            res.push_back(s[i]);
        }
        removeChar(s,n, i+1, c, res);
    }

public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c) {
        string res = "";
        int n = s.size();
        int idx = 0;
        removeChar(s,n,idx, c, res);
        s = res;

    }
};

