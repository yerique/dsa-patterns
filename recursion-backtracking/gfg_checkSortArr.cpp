//gfg_Check Sorted Array

class Solution {
public:
    bool isSort(vector<int>& arr, int n, int idx){
        if(idx == n || idx == n - 1){
            return true;
        }
        if(arr[idx] > arr[idx+1]){
            return false;
        }
        return isSort(arr, n, idx + 1);
    }

public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        return isSort(arr, n, i);
    }
};
