#include<iostream>
using namespace std;

int main ()
{
   int a,b,c,p,avg;
   cout<<"Enter value of a : ";
   cin>>a;
   cout<<"Enter value of b : ";
   cin>>b;
   cout<<"Enter value of c : ";
   cin>>c;
   p = a*b*c;
   avg = (a+b+c)/3;
   cout<<"Their product is : "<<p<<endl;
   cout<<"Their average is : "<<avg<<endl;

  return 0;
}
