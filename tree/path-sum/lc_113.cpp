//113. Path Sum II

public:
vector<vector<int>> res;
void pathSumTar(TreeNode* node, int target, int currSum, vector<int> diary){
    if(!node){
        return;
    }
    currSum += node->val;
    diary.push_back(node->val);
    if(!node->left && !node->right){
        if(currSum == target){
            res.push_back(diary);
            diary.pop_back();
            return;
        }
    }
    pathSumTar(node->left, target, currSum, diary);
    pathSumTar(node->right, target, currSum, diary);
    diary.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root){
        return {};
    }
    vector<int> diary;
    pathSumTar(root, targetSum, 0, diary);
    return res;
}
};
