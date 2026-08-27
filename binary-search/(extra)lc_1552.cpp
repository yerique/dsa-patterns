//1552. Magnetic Force Between Two Balls

class Solution {
public:
    bool possible(vector<int>& position, int n, int m, int guess){
        int balls = 1;
        int prevPos = position[0];
        for(int i = 0; i < n; i++){
            int force = position[i] - prevPos;
            if(force < guess){
                continue;
            }
            balls++;
            prevPos = position[i];
        }
        if(balls >= m){
            return true;
        }else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 0; int high = position[n-1] - position[0];
        int res = -1;
        while (low <= high){
            int guess = (low + high)/2;
            if(possible(position, n, m, guess)){
                res = guess;
                low = guess + 1;
            }else{
                high = guess - 1;
            }
        }
        return res;
    }
};
