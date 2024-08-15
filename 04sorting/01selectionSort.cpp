#include <bits/stdc++.h>
using namespace std ;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//finds min elemt from the unsorted portion of list, swaps it with first elmt of unsorted section

void selectionSort(int arr[], int n){

for (size_t i = 0; i < n-1; i++)
{
    int min =i;
    for (size_t j = i+1; j<n; j++)
    {
        if(arr[j]<arr[min]) min=j;
    }
    swap(&arr[i],&arr[min]);
}

//display
for (size_t i = 0; i < n; i++)
{
    cout<<arr[i]<<", ";
}

}


int main(){
int arr[]={1,9,2,4,5,10,7,3,6,8};
int n=sizeof(arr)/sizeof(arr[0]);
selectionSort(arr,n);

}