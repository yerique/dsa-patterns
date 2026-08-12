//Triplets with Smaller Sum

class Solution {
public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int count = 0 ;

        for ( int i = 0; i < n-2; i++){

            int l = i + 1;
            int r = n - 1 ;

            while (l < r){

                int s = arr[i] + arr[l] + arr[r];

                if (s >= sum){
                    r--;
                }
                else {
                    count = count + (r - l);
                    l++;
                }
            }
        }
        return count;
    }
};