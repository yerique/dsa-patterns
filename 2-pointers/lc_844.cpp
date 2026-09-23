//844. Backspace String Compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0; int k = 0; // idx k is storing the survived char for s
        int j = 0; int p = 0; // idx p is storing the survived char for t
        while(i < n){
            if(s[i] != '#'){
                s[k] = s[i];
                k++;
            }else{
                k--;
                if(k < 0) k = 0;
            }
            i++;
        }
        while(j< m){
            if(t[j] != '#'){
                t[p] = t[j];
                p++;
            }
            else{
                p--;
                if(p < 0) p = 0;
            }
            j++;
        }
        if(k != p){
            return false;
        }else{
            for(int i = 0; i < k; i++){
                if(s[i] != t[i]) return false;
            }
            return true;
        }
    }
};