//57. Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool inserted = false;
        for(int i = 0; i < n; i++){
            int start = intervals[i][0];
            if(inserted == false && start >= newInterval[0]){
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(intervals[i]);
        }
        if(inserted == false) { //i.e., newInt is greatest among all.
            res.push_back(newInterval);
        }
        vector<vector<int>> merged;
        int start_1 = res[0][0];
        int end_1 = res[0][1];
        for(int i = 1; i < n + 1; i++){ //+1 cuz we inserted one
            int s = res[i][0];
            int e = res[i][1];
            if(end_1 >= s){
                start_1 = start_1;
                end_1 = max(end_1, e); // we are merging the interval by this
                continue;   //but there can be more so no adding into merged yet
            }
            // if we reach here means end_1 < s --> eg:[1,5] [6,7]
            merged.push_back({start_1, end_1});  //so add [1,5] into merged
            start_1 = s;      //the merging may still be needed for later el.
            end_1 = e;        // so thig goes n goes
        }
        //till we get to end of the res array ended
        merged.push_back({start_1, end_1});
        return merged;
    }
};