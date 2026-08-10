#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;
  vector <int> v;

  for (int i=0; i<n; i++){
    int x;
    cout<<"Enter elements here: ";
    cin>>x;
    v.push_back(x);
  }
  for (int j=n-1; j>=0; j--) {
      cout<<v[j];
  }
  return 0;
 }