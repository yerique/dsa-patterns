//145. Binary Tree Postorder Traversal

public:
void helper(TreeNode* &node,  vector<int> &res){
    if(node == nullptr){
        return;
    }
    helper(node->left, res);
    helper(node->right, res);
    res.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}
};
