#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
cout<<"Enter n- >";
cin>>n;
int arr[n]={};
for (size_t i = 0; i < n; i++)
{
    cin>>arr[i];
}


unordered_map<int, int> mpp;
for (size_t i = 0; i < n; i++)
{
    mpp[arr[i]]++;
}
int high,low;
int big=INT_MIN, less=INT_MAX;
for(auto it: mpp){
if(it.second>big){
    big=it.second;
    high=it.first;
}
if(it.second<less){
    less=it.second;
    low=it.first;
}
}


for(auto it: mpp){
    cout<<it.first<<"->"<<it.second<<endl;
}

cout<<"Highest freq- "<<high<<endl;
cout<<"lowest freq- "<<low;



}