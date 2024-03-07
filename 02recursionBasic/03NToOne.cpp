#include<bits/stdc++.h>
using namespace std;

void reverseRec(int n){
if(n<1) return;
cout<<n<<" ";
reverseRec(n-1);
}

int main()
{
int n;    
cout<<"enter n - ";
cin>>n;   
reverseRec(n);
}