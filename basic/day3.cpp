#include<iostream>
using namespace std;

//Given an integer n. Your task is to calculate the sum of all natural numbers from 1 up to n (inclusive). If n is 0, the sum should be 0.

int findSum (int n){
  if(n==0) return 0;
  int sum = (n*(n+1))/2;
  return sum;
}

int main(){

  //cout<<findSum(10);

  int m =10;
  int result = findSum(m);
  cout<<result;

  return 0;
}
