#include<bits/stdc++.h>
using namespace std;
//Using Euclidean Algorithm
int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if(a>b) a=a%b;
    else b=b%a;
  }
  if(a==0) return b;
  return a;
}


int main()
{
 int hcf=gcd(134134,343);
 cout<<hcf;
}

//O(log(min(a, b)))