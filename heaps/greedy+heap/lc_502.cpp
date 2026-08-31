//502. IPO

//this is my solution works but can be alot better
//from this question i am coding/debugging problem in local clion: hence header file and stuff
#include<bits/stdc++.h>
using namespace std;
 struct cmp {
     bool operator()(const pair<int, int>&a, const pair<int, int>&b) const{
         if(a.first != b.first) return (a.first < b.first);
         return (a.second > b.second);
     }
 };
 class Solution {
 public:
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int psize = profits.size();
         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
         for(int i = 0; i < psize; i++){
             int p = profits[i];
             int c = capital[i];
             pq.push({p,c});
         }

         int noOfProj = 1;

         while(noOfProj <=k && !pq.empty()){
             bool projectExecuted = false;

             vector<pair<int,int>>temp;

             while(!pq.empty()){
                 pair<int,int> proj = pq.top(); pq.pop();
                 int prof = proj.first;
                 int cap = proj.second;
                 if(w >= cap){
                     noOfProj++;
                     w += prof;
                     projectExecuted = true;
                     break;
                 }else{
                     temp.push_back(proj);
                 }
             }
             for(auto proj : temp){
                 pq.push(proj);
             }
             if(!projectExecuted){
                 break;
             }

         }
         return w;
     }
 };
// better soln here:
 class Solution2 {
 public:
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int n = profits.size();
         vector<pair<int, int>> projects;
         for (int i = 0; i < n; i++) {
             projects.push_back({capital[i], profits[i]});
         }
         sort(projects.begin(), projects.end());
         priority_queue<int> pq; int idx = 0;
         while (k--) {
             while (idx < n) {
                 if (projects[idx].first > w) {
                     break;
                 }
                 pq.push(projects[idx].second);
                 idx++;
             }
             if (pq.empty()) {
                 return w;
             }
             w += pq.top();
             pq.pop();
         }
         return w;
     }
 };

int main() {
    Solution solver;
    int k = 3;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 2};

    int ans = solver.findMaximizedCapital(k, w, profits, capital);
    cout << "Result: " << ans << endl;

    return 0;
}