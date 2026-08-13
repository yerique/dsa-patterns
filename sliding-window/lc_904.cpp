//904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;
        int max_fruits = 0;
        unordered_map<int, int> bks;

        for ( int high = 0; high < n; high++){
            bks[fruits[high]]++;

            while (bks.size() > 2) {
                bks[fruits[low]]--;

                if(bks[fruits[low]] == 0) {
                    bks.erase(fruits[low]);
                }

                low++;
            }
            int len = high - low + 1;
            max_fruits = max(len, max_fruits);
        }

        return max_fruits;
    }
};
