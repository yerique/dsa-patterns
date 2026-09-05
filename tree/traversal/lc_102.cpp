//102. Binary Tree Level Order Traversal

#include<bits/stdc++.h>;
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            int lvlSize = que.size();
            vector<int> temp;
            while(lvlSize--){
                TreeNode* t = que.front();
                que.pop();
                temp.push_back(t->val);
                if(t->left){
                    que.push(t->left);
                }
                if(t->right){
                    que.push(t->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    /* asked test-case from gemini to test locally didn't asked the solution from it.
     * Constructing the test tree:
     *         3
     *        / \
     *       9   20
     *          /  \
     *         15   7
     */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solver;
    vector<vector<int>> result = solver.levelOrder(root);

    // Print the level order output
    cout << "[\n";
    for (const auto& level : result) {
        cout << "  [ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }
    cout << "]" << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}