//112. Path Sum

class Solution {
public:
    bool res = false;
    void hasPathTar(TreeNode* node, int target, int currSum){
        if(!node){
            return;
        }
        currSum += node->val; //currNode has to part of some path right so include
        if(!node->left && !node->right){
            if(currSum == target){
                res = true;
                return;
            }
        }
        hasPathTar(node->left, target, currSum);
        hasPathTar(node->right, target, currSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // res = false; just setting to fal for futher calling of the func in same program, (interview tweak)
        if(!root){
            return false;
        }
        hasPathTar(root, targetSum, 0);
        return res;
    }
};
