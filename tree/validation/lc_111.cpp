//111. Minimum Depth of Binary Tree

//not just 1 + min(left, right) --> if either one child is null we shouldm't consider it cuz it is min
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){ //both null means leaf node so alone node depth is 1
            return 1;
        }
        if(!root->left){ // left is null and if control comes here means right is not null
            return 1 + minDepth(root->right); //so not even considering left just right gets involved
        }
        if(!root->right){ //same here left is not null and right is
            return 1 + minDepth(root->left); //ignore the existence of right just see left;
        }
        return 1 + min(minDepth(root->right), minDepth(root->left)); //normal case where both are not null so no issue
    }
};
