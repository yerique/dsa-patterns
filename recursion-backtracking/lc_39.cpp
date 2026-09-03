//39. Combination Sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void comboSum(vector<int>&candidates, int n, int idx, vector<int>& diary, int sum, int target, vector<vector<int>>& res){
      if(idx == n){
        if(sum == target){
          res.push_back(diary);
        }
          return;
      }
      //not include
      comboSum(candidates, n, idx + 1, diary, sum, target, res);

      //include
      if(sum + candidates[idx] <= target){
          diary.push_back(candidates[idx]);
          sum += candidates[idx];
          comboSum(candidates, n, idx, diary, sum, target, res);
          diary.pop_back();
          sum -= candidates[idx];
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> diary;
        int sum = 0;
        int idx = 0;
        vector<vector<int>> res;
        comboSum(candidates, n, idx, diary, sum, target, res);
        return res;
    }
};

int main() {
    Solution solver;

    // Standard test case (LeetCode 39: Combination Sum)
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    cout << "Target: " << target << "\n";
    cout << "Candidates: [2, 3, 6, 7]\n";
    cout << "-----------------------\n";

    vector<vector<int>> result = solver.combinationSum(candidates, target);

    cout << "Resulting Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
