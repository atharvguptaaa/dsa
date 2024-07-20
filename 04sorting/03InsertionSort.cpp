#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
for(int i=0;i<n;i++){
int j=i;
    while(j>0&&arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
    }
}



//display
for (size_t i = 0; i < n; i++)
{
    cout<<arr[i]<<", ";
}
}

int main()
{
int arr[]={1,9,2,4,5,10,7,3,6,8};
int n=sizeof(arr)/sizeof(arr[0]);
insertionSort(arr,n);

}