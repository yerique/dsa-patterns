//22. Generate Parentheses

class Solution {
private:
    void generateParen(int n, int noOfOpen, int noOfClose, string &currStr, vector<string> &res){
        if(noOfOpen == n && noOfClose == n){
            res.push_back(currStr);
            return;
        }
        if(noOfOpen < n){
            currStr.push_back('(');
            generateParen(n , noOfOpen + 1, noOfClose, currStr, res);
            currStr.pop_back();

        }
        if (noOfClose < noOfOpen){
            currStr.push_back(')');
            generateParen(n, noOfOpen, noOfClose + 1, currStr, res);
            currStr.pop_back();
        }
    };
public:
    vector<string> generateParenthesis(int n) {
        int noOfOpen = 0;
        int noOfClose = 0;
        string currStr = "";
        vector<string> res;
        generateParen(n, noOfOpen, noOfClose, currStr,res);
        return res;
    }
};
