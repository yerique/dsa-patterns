//17. Letter Combinations of a Phone Number

class Solution {
private:
    void letterCombo(string digits, int n, int idx, string &diary, vector<string> &res, unordered_map<char, string>&map){
        if(idx == n){
            res.push_back(diary);
            return;
        }
        string choice = map[digits[idx]];
        for(int i = 0; i < choice.size(); i++){
            diary.push_back(choice[i]);
            letterCombo(digits, n, idx + 1, diary, res, map);
            diary.pop_back();
        }
    };
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc"; map['3'] = "def"; map['4'] = "ghi"; map['5'] = "jkl";
        map['6'] = "mno"; map['7'] = "pqrs"; map['8'] = "tuv"; map['9'] = "wxyz";
        int idx = 0; int n = digits.size();
        string diary = ""; vector<string> res;
        letterCombo(digits, n, idx, diary, res, map);
        return res;

    }
};

