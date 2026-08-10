#include<iostream>
using namespace std;

int main(){
  int sum =0;
  for (int i=0; i<=10; i++) {
    sum = sum + i;
  }
  cout<<"Sum of first 10 numbers are: "<<sum<<endl;

  int sumEven = 0;
  for (int i =0; i<=20; i++) {
    if (i%2 == 0) {
      sumEven = sumEven + i;
    }
  }
  cout<<"Sum of first 10 even numbers are: "<<sumEven<<endl;

  int sum20_40 = 0;
  for (int i=20; i<=40; i++) {
    if (i%2==0) {
      sum20_40 = sum20_40 + i;
    }
  }
  cout<<"Sum of even numbers b/w 20 and 40 (both included) are: "<<sum20_40<<endl;
  return 0;
  }