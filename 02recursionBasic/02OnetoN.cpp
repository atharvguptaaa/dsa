#include<bits/stdc++.h>
using namespace std;



void printNTimes(int i, int n){
    if(i>n) return;
    cout<<i;
    printNTimes(i+1,n);
}



int main()
{
    string name;
    int n;
    cout<<"enter n - ";
    cin>>n;
    printNTimes(1,n);
}