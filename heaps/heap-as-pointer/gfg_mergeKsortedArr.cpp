//Merge k Sorted Arrays
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val; int row; int col;
    Node(int v, int r, int c){
        val = v; row = r; col = c;
    }
};

struct cmp{
    bool operator()(const Node &a, const Node &b){
        return (a.val > b.val);
    }
};


class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n = mat.size(); //row
        int m = mat[0].size(); //col
        priority_queue<Node, vector<Node>, cmp> pq;
        for(int i = 0; i < n; i++){
            pq.push({mat[i][0], i, 0});
        }
        vector<int> res;
        while(!pq.empty()){
            Node curr = pq.top(); pq.pop();
            res.push_back(curr.val);
            if(curr.col < m - 1){
                pq.push({mat[curr.row][curr.col + 1], curr.row, curr.col + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution solver;

    // Create a test case: 3 sorted arrays
    vector<vector<int>> mat = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> result = solver.mergeArrays(mat);

    // Output the result
    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}