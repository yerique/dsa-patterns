//236. Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* ans = nullptr;
    int lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node){
            return 0;
        }
        int left = lca(node->left, p, q);
        int right = lca(node->right, p, q);
        int self = 0;
        if(node == p || node == q){
            self = 1;
        }
        int total = left + self + right;
        if(total == 2 && ans == nullptr){
            ans = node;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        lca(root, p, q);
        return ans;


    }
};