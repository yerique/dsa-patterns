//56. Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start_1 = intervals[0][0];
        int end_1 =intervals[0][1];
        vector<vector<int>> res;

        for(int i = 1; i < n; i++) {
            int start_2 = intervals[i][0];
            int end_2 =intervals[i][1];
            if(end_1 >= start_2) {
                start_1 = start_1;
                end_1 = max(end_1, end_2);
                continue;
            }
            res.push_back({start_1, end_1});
            start_1 = start_2;
            end_1 = end_2;
        }
        res.push_back({start_1, end_1});
        return res;
    }
};