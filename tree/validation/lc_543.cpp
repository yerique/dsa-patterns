//543. Diameter of Binary Tree

class Solution {
public:
    int res = 0;
    int height(TreeNode* node){
        if(!node){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int sum = left + right;
        res = max(res, sum);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};