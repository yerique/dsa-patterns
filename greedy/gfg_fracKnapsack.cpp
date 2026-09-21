//gfg_Fractional Knapsack

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        double res = 0;
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push({(double)val[i]/wt[i], i});
        }
        while(!pq.empty() && capacity > 0){
            auto [ratio, idx] = pq.top();
            pq.pop();
            if(wt[idx] <= capacity){
                res += val[idx];
                capacity -= wt[idx];
            }else{
                res += ratio * capacity;
                capacity = 0;
            }
        }
        return res;
    }
};
