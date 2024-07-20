#include<bits/stdc++.h>
using namespace std;
int main()
{
 vector<int> arr={1,2,3,4,5,6,7,8,9};
 int n=arr.size();
 int temp=arr[0];
 for (size_t i = 1; i < n; i++)
 {
    arr[i-1]=arr[i];
 }
 arr[n-1]=temp;
 //display
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
}