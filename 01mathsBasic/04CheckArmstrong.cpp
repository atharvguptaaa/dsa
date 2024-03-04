#include<bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n){
  if (n<0)
  return false;
	int dup=n;
    int m=n;
	int arm=0;
    int digits=0;
  while(m!=0){
    m=m/10;
    digits++;
  }
  while (n != 0) {
	  arm=arm+pow((n%10),digits);
		n=n/10;
  }
  if (dup==arm)
  return true;
  else
  return false;
}

int main()
{
 bool yORn= checkArmstrong(1634);
 cout<<yORn;
}