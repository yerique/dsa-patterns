//Sum Of Digits

class Solution {
public:
    int sumOfDigits(int n) {
        if(n == 0){
            return 0;
        }
        int last = n % 10;
        int left = n /10;
        int ans = sumOfDigits(left);
        return last + ans;
    }
};
