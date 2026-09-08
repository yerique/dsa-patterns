//98. Validate Binary Search Tree

class Solution {
public:
    TreeNode* prev = nullptr;
    bool ans = true;
    void isValIno(TreeNode* node){
        if(!node){
            return;
        }
        isValIno(node->left);
        if(!prev){
            prev = node;
        }else{
            if(node->val <= prev->val){
                ans = false;
            }
            prev = node;
        }
        isValIno(node->right);
    }
    bool isValidBST(TreeNode* root) {
        isValIno(root);
        return ans;
    }
};
