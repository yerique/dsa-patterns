//105. Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
public:
    unordered_map<int, int> inoToi;
    void mapInoToi(vector<int>& inorder){ // mappin inorder val to idx
        for(int i = 0; i < inorder.size(); i++){
            inoToi[inorder[i]] = i;
        }
        return;
    }
    int idx = 0; // going throgh pre
    TreeNode* building(vector<int>& preorder, int low, int high){
        if(low > high){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[idx]);
        int id = inoToi[preorder[idx]];
        idx++;
        node->left = building(preorder, low, id - 1);
        node->right = building(preorder, id + 1, high);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapInoToi(inorder);
        return building(preorder, 0, inorder.size() - 1);

    }
};
