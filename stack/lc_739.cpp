//739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> nextMoreTempIndex;
        nextMoreTempIndex.push(n-1);
        vector<int> res;
        res.push_back(0);
        for(int i = n-2; i >= 0; i--){
            while(!nextMoreTempIndex.empty() && temperatures[i] >= temperatures[nextMoreTempIndex.top()]) {
                nextMoreTempIndex.pop();
            }
            if(nextMoreTempIndex.empty()){
                res.push_back(0);
            } else{
                int days = nextMoreTempIndex.top() - i; //top index - now index gives the days b/w them
                res.push_back(days);
            }
            nextMoreTempIndex.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};