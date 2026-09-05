//226. Invert Binary Tree

class Solution {
public:
    TreeNode* invert(TreeNode* node){
        if(!node){
            return nullptr;
        }
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert(node->left);
        invert(node->right);
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        return invert(root);
    }
};
