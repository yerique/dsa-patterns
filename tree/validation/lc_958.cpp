//

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        bool nullFound = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* t = que.front();
            que.pop();
            if(!t){
                nullFound = true;
            }
            else{
                if(nullFound){
                    return false;
                }
                que.push(t->left);
                que.push(t->right);
            }
        }
        return true;
    }
};