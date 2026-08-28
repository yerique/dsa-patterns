//gfg_Allocate Minimum Pages

class Solution {
public:
    bool possible(vector<int> &arr,int n, int k, long long limit){
        int stud = 1;
        long long pages = 0;
        for(int i = 0; i < n; i++){
            if(pages + arr[i] <= limit){
                pages += arr[i];
            }else{
                stud++;
                pages = arr[i];
                if(stud > k){
                    return false;
                }
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k) return -1;
        long long low = 0; long long high = 0;
        for(int  pages: arr){
            low = max(low, (long long)pages);
            high += pages;
        }
        long long res = -1;
        while(low <= high){
            long long guess = (low + high)/2;
            if(possible(arr, n, k, guess)){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};
