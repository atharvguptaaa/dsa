#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
	int count=0;
  while (n != 0) {
  n=n/10;
  count++;
  }
  return count;
}

int main()
{
int digits= countDigits(40);
cout<< digits;
}