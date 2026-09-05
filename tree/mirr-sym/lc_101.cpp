//101. Symmetric Tree

class Solution {
public:
    bool isMirror(TreeNode* lchild, TreeNode* rchild){
        if(!lchild && !rchild){
            return true;
        }
        if(!lchild || !rchild){
            return false;
        }
        if(lchild->val != rchild->val){
            return false;
        }
        bool mirr1 = isMirror(lchild-> left , rchild->right);
        bool mirr2 = isMirror(lchild->right , rchild->left);

        return mirr1 && mirr2;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return false;
        }
        return isMirror(root->left, root->right);
    }
};
