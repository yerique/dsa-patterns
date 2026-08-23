//1189. Maximum Number of Balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        int res = INT_MAX;
        unordered_map<char, int> have;
        for(int i = 0; i < n; i++){
            have[text[i]]++;
        }
        unordered_map<char,int> balloon;
        balloon['b'] = 1; balloon['a'] = 1; balloon['l'] = 2;
        balloon['o'] = 2; balloon['n'] = 1;
        for(auto i: balloon){
            int c = i.first;
            int times = have[c]/balloon[c];
            res = min(res, times);
        }
        return res;
    }
};