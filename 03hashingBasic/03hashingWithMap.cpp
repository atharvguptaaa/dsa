#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
int arr[n]={};
cout<<"Enter n- ";
cin>>n;
cout<<"Enter arr elements ";
for (int i = 0; i< n; i++)
{
   cin>>arr[i];
}           
//precompute
unordered_map<int,int> mpp;
for (int i = 0; i < n; i++)
{
    mpp[arr[i]]++;
}
cout<<"Enter q- ";
int q;
cin>>q;
cout<<"Enter query elements- ";
int query[q]={};
for (int i = 0; i < q; i++)
{
   cin>>query[i];
}

for(auto it: mpp){
    cout<<it.first<<"->"<<it.second<<endl;
}

cout<<"Hash: ";
for (size_t i = 0; i < q; i++)
{
  cout<<mpp[query[i]]<<endl;
}

}