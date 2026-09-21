//201. Bitwise AND of Numbers Range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = right & (right - 1);
        }
        return left & right;
    }
};
