/* random question found on twitter
### Find the Element Occurring Less Than K Times

You are given a sorted integer array nums and an integer k.

- Every distinct element in nums occurs exactly k times, except for one element.
- The exceptional element occurs fewer than k times.
- Return the exceptional element.

You must design an algorithm that runs in O(log n) time and uses O(1) extra space.

### Example 1

Input:

nums = [1,1,1,2,2,2,3,3,4,4,4,5,5,5]
k = 3

Output:

3

Explanation:

All elements occur exactly 3 times except 3, which occurs only twice.

### Example 2

Input:

nums = [1,1,2,2,2,3,3,3,4,4,4]
k = 3

Output:

1

Explanation:

1 occurs only twice, while every other element occurs exactly 3 times.

### Example 3

Input:

nums = [1,1,1,2,2,2,3,3]
k = 3

Output:

3

### Constraints

1 <= nums.length <= 10^5
1 <= k <= nums.length
1 <= nums[i] <= 10^9

nums is sorted in non-decreasing order.

There is exactly one element whose frequency is less than k.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int k){
    int low = 0; int high = arr.size()/k; // this give idx of no of grps possible (lets say of 111, 22, 333 and k = 3 then 8/3 = 2 ie grps 0, 1, 2)
    while(low < high){
        int guess = (low + high)/2;
        int expectedStart = guess * k; //we get what should have been the start idx of that grp in main array from the grp idx
        int expectedEnd = expectedStart + k - 1;
        if(expectedEnd < arr.size() && arr[expectedStart] == arr[expectedEnd]){
            low = guess + 1;
        }else{
            high = guess;
        }
    }
    return arr[low * k];
}
int main() {

    // Test 1: anomaly in the middle
    vector<int> arr1 = {
        1,1,1,
        2,2,
        3,3,3,
        4,4,4,
        5,5,5
    };

    int k1 = 3;

    cout << "Test 1: " << solve(arr1, k1) << endl;
    cout << "Expected: 2" << endl;


    // Test 2: anomaly at the end
    vector<int> arr2 = {
        1,1,1,
        2,2,2,
        3,3,3,
        4,4
    };

    int k2 = 3;

    cout << "Test 2: " << solve(arr2, k2) << endl;
    cout << "Expected: 4" << endl;

    return 0;
}
