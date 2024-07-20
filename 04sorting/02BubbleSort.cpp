#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
for(int i=n-1; i>=1; i--){
 int didSwap=0; //to terminate loop if its a sorted array (after each pass)
    for(int j=0;j<=i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j], arr[j+1]);
            didSwap=1;
        }
    }
     if(didSwap==0)
     break;
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
bubbleSort(arr,n);

}