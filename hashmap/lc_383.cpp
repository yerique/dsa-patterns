//383. Ransom Note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        unordered_map<char, int> need;
        for(int i = 0; i < n; i++){
            need[ransomNote[i]]++;
        }
        int m = magazine.size();
        unordered_map<char, int> have;
        for(int i = 0; i < m; i++){
            have[magazine[i]]++;
        }
        for(auto i: need){
            int c = i.first;
            if(have[c] < need[c]){
                return false;
            }
        }
        return true;
    }
};