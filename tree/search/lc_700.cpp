//700. Search in a Binary Search Tree

class Solution {
public:
    TreeNode* ans = nullptr;
    void search(TreeNode* node, int target){
        if(!node){
            return;
        }
        if(node->val < target){
            search(node->right, target);
        }
        else if(node->val > target){
            search(node->left, target);
        }
        else{
            ans = node;
            return;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return root;
        }
        search(root, val);
        return ans;
    }
};