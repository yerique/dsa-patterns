//202. Happy Number

class Solution {
public:
    int sumSq(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = sumSq(slow);
            fast = sumSq(fast);
            fast = sumSq(fast);

            if( fast != 1 && slow == fast ) {
                return false;
            }
        }
        return true;
    }
};