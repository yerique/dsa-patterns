//860. Lemonade Change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        if(bills[0] != 5) return false;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){ //no change to give back
                fives++;
            }
            else if(bills[i] == 10){ //5 to give back
                if(fives == 0) return false;
                fives--;
                tens++;
            }else{ // bill[i] = 20 to have to give 15 back
                if(tens > 0){
                    if(fives == 0) return false;
                    tens--;
                    fives--;
                }else{
                    if(fives < 3) return false;
                    fives = fives - 3;
                }
            }
        }
        return true;
    }
};