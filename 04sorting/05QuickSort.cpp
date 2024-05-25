#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int i=low, j=high;
    int pivot=low;
    while(i<j){
        while(arr[i]<=arr[pivot]&&i<=high-1){
            i++;
        }
        while(arr[j]>arr[pivot]&&j>=low+1){
            j--;
        }
       if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qS(vector<int> &arr, int low, int high){

    if(low<high){
        int pIndex=partition(arr, low, high);
        qS(arr,low,pIndex-1);
        qS(arr,pIndex+1,high);
    }
}

int main()
{
vector<int> arr={1,9,2,4,5,10,7,3,6,8};
int n=arr.size();
qS(arr,0,n-1);

//display the sorted array
for (size_t i = 0; i < n; i++)
{
    cout<<arr[i]<<", ";
}

}