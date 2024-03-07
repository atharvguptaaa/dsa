#include<bits/stdc++.h>
using namespace std;

int sum=0;
void SumUptoN(int n){
    sum=sum+n;
    if(n<1) {
    cout<<sum;
    return;}
    SumUptoN(n-1);
}

int main()
{
    int n;    
    cout<<"enter n - ";
    cin>>n;   
    SumUptoN(n);
}