//762. Prime Number of Set Bits in Binary Representation

class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++){
            int n = i;
            int count = 0;
            while(n>0){
                n = n & (n -1);
                count++;
            }
            if(isPrime(count)){
                res++;
            }
        }
        return res;
    }
};
