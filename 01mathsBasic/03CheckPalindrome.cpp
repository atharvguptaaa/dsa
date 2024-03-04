#include<bits/stdc++.h>
using namespace std;

bool palindrome(int n)
{
    int s=n;
    int nn=0;
    while(n!=0){
        int ld=n%10;
        n=n/10;
        nn= (10*nn)+ld;
    }
    if(nn==s)
    return true;
    else
    return false;
}

int main()
{
  bool yORn=  palindrome(131);
  cout<<yORn;
 
}
