//110. Balanced Binary Tree

class Solution {
public:
    bool res = true;
    int isBal(TreeNode* node){
        if(!node){
            return 0;
        }
        int left = isBal(node->left);
        int right = isBal(node->right);
        if(abs(left - right) > 1){
            res = false;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        isBal(root);
        return res;
    }
};