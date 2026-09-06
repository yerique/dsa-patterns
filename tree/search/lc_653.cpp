//653. Two Sum IV - Input is a BST

class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> dsc;
    TreeNode* getSmall(){
        if(asc.empty()){
            return nullptr;
        }
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightChild = small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }
    TreeNode* getBig(){
        if(dsc.empty()){
            return nullptr;
        }
        TreeNode* big = dsc.top();
        dsc.pop();
        TreeNode* leftChild = big->left;
        while(leftChild){
            dsc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        TreeNode* t = root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            dsc.push(t);
            t = t -> right;
        }
        TreeNode* low = getSmall();
        TreeNode* high = getBig();
        while(low && high && low != high && low->val < high->val){
            int sum = low->val + high->val;
            if(sum == k){
                return true;
            }
            else if(sum > k){
                high = getBig();
            }else{
                low = getSmall();
            }
        }
        return false;
    }
};