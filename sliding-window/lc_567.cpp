//567. Permutation in String


class Solution {
public:
    bool PermMatch(vector<int>& need, vector<int>& have){
        for(int i = 0;  i < 26; i++){
            if(need[i] != have[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int>need(26, 0);
        for(int i = 0; i < n; i++){
            need[s1[i] - 'a']++;
        }
        int low = 0; int high = n - 1;
        vector<int>have(26, 0);
        for(int i = low; i <= high; i++){
            have[s2[i] - 'a']++;
        }
        while(high < m){
            if(PermMatch(need, have)){
                return true;
            }
            if(high == m - 1) break;
            have[s2[low] - 'a']--;
            low++;

            high++;
            have[s2[high] - 'a']++;

        }
        return false;
    }
};
