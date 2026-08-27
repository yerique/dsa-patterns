//875. Koko Eating Bananas

class Solution {
public:
    long long getHoursForASpeed(vector<int>& piles, int n, int k){
        long long hours = 0;
        for(int i = 0; i<n; i++){
            hours += piles[i]/k;
            if(piles[i]%k != 0){
                hours++;
            }
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1; //lowest speed
        int high = 0;
        for(int pile: piles){
            high = max(high, pile);//highest speed-> no.of banana in highes pile
        }
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            long long hours = getHoursForASpeed(piles, n, guess);
            if(hours > h){//koko can't finish in time
                low = guess + 1; //forget about even slower speeds, look higher
            }else{  //can finish it.
                res = guess;  //but koko might finish even if it eats lil slower
                high = guess - 1; //and we want that so save it and look slower
            }
        }
        return res;
    }

};
