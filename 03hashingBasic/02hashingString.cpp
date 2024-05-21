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

int hash[13]={} ;
for (int i = 0; i < n; i++)
{
    hash[arr[i]]+=1;
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

cout<<"Hash: ";
for (size_t i = 0; i < q; i++)
{
  cout<<hash[query[i]]<<endl;
}

}