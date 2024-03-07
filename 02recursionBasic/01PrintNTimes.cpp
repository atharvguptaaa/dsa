#include<bits/stdc++.h>
using namespace std;


int cnt=0;
void printNTimes(string name, int n){
    if(cnt==n) return;
    cout<<name<<"\n";
    cnt++;
    printNTimes(name, n);
}



int main()
{
 string name;
 int n;
cout<<"enter name - ";
cin>>name;
cout<<"enter times - ";
cin>>n;
printNTimes(name,n);
}