//787. Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        int times = k + 1;
        while(times--){
            vector<int> temp = res;
            for(int i = 0; i < flights.size(); i++){
                int s = flights[i][0];
                int d = flights[i][1];
                int wt = flights[i][2];
                if(res[s] == 1e8) continue;
                int newWt = res[s] + wt;
                if(newWt < temp[d]){
                    temp[d] = newWt;
                }
            }
            res = temp;
        }
        return (res[dst] == 1e8) ? -1 : res[dst];
    }
};
