//99. Recover Binary Search Tree

class Solution {
public:
    int wrongTimes = 0;
    TreeNode* prev = nullptr;
    TreeNode* left1 = nullptr; TreeNode* right1 = nullptr;
    TreeNode* left2 = nullptr;  TreeNode* right2 = nullptr;

    void recT(TreeNode* node){
        if(!node) return;
        recT(node->left);
        if(!prev){
            prev = node;
        }else{
            if(node->val <= prev->val){
                if(wrongTimes == 0){
                    left1 = prev;
                    right1 = node;
                }else{
                    left2 = prev;
                    right2 = node;

                }
                wrongTimes++;
            }
            prev = node;
        }
        recT(node->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        recT(root);
        if(wrongTimes == 1){
            swap(left1->val, right1->val);
        }else{
            swap(left1->val, right2->val);
        }
        return;
    }
};
