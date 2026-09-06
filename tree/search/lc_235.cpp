//235. Lowest Common Ancestor of a Binary Search Tree

class Solution {
public:
    TreeNode* ans = nullptr;
    void lcaBst(TreeNode* node, TreeNode* smallerNode, TreeNode* greaterNode){
        if(!node){
            return;
        }
        if(node == smallerNode || node == greaterNode){
            ans = node;
            return;
        }
        if(node->val < smallerNode->val){
            lcaBst(node->right, smallerNode, greaterNode);
        }
        else if(node->val > greaterNode->val){
            lcaBst(node->left, smallerNode, greaterNode);
        } else{
            ans = node;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        if(p->val < q->val)lcaBst(root, p, q);
        else lcaBst(root, q, p);
        return ans;

    }
};