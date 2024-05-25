#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
    vector <int> temp;
    int left=low,right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
            }
        else{
            
            temp.push_back(arr[right]);
            right++;
        }
    }
    
        while(right<=high){
        temp.push_back(arr[right]);
        right++;
    
    }
    
        while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    

   // Copy the sorted elements back to the original array
   for (size_t i = low; i <= high; i++)
   {
    arr[i]=temp[i-low];
   }
   
    

    }


void mS(vector<int> &arr,int low,int high){
    if(low<high){
    int mid=(high+low)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
    }

}

int main()
{
vector<int> arr={1,9,2,4,5,10,7,3,6,8};
int n=arr.size();
mS(arr,0,n-1);

//display the sorted array
for (size_t i = 0; i < n; i++)
{
    cout<<arr[i]<<", ";
}

}