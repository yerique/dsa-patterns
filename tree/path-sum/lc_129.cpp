//129. Sum Root to Leaf Numbers

class Solution {
public:
    int combineSum = 0;
    void sumNum(TreeNode* node, int tillNow){
        if(!node){
            return;
        }
        int combo = tillNow*10 + node->val;
        if(!node->left && !node->right){
            combineSum += combo;
            return;
        }
        sumNum(node->left, combo);
        sumNum(node->right, combo);
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        sumNum(root, 0);
        return combineSum;
    }
};
