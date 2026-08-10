//Segregate 0s and 1s
https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;

        while(i<j){
            if(arr[i]<arr[j] && arr[i] == 0){
                i++;
                j--;
            }
            else if (arr[i]>arr[j] && arr[i] == 1){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else if(arr[i] == 1){
                j--;
            }
            else {
                i++;
            }
        }

    }
};

//2nd way
class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;

        while(i<j){
            if(arr[i] == 0){
                i++;
            }
            else if(arr[j] == 1){
                j--;
            }
            else{
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

    }
};