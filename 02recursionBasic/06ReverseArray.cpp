#include<bits/stdc++.h>
using namespace std;

// void swap(int arr[],int a, int b){
//     int c= arr[a];
//     arr[a]=arr[b];
//     arr[b]=c;
// }

// void f(int a[],int l, int r){
//     if(l>=r)return ;
//     swap(a,l,r);
//     f(a,l+1,r-1);

// }

// int main()
// {
//  int a[]={1,2,3,4,5,6};
//  cout<<sizeof(a)/sizeof(a[0])<<"////";
//  f(a,0,4);
// for(int i=0; i<=sizeof(a)/sizeof(a[0])-1;i++)
// {
//     cout<<a[i]; 
//  }
// }



void f(int a[],int i, int n){
    if(i>=n/2) return;
    swap(a[i],a[n-i-1]);
    f(a,i+1,n);
}



int main()
{
 int a[]={1,2,3,4,5,6};
 int n=sizeof(a)/sizeof(a[0]);
 cout<<n<<"////";
 f(a,0,n);
for(int i=0; i<=n-1;i++)
{
    cout<<a[i]; 
 }
}
