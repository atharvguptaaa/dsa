#include<bits/stdc++.h>
using namespace std;
////Brute Force approach: 

// void rotateArray(vector<int> arr,int n, int d){
//     d=d%n;
//     vector<int> temp;
//     for (size_t i = 0; i < d; i++)
//     {
//         temp.push_back(arr[i]);
//     }
//     for (size_t i = d; i < n; i++)
//     {
//         arr[i-d]=arr[i];
//     }
//     for (size_t i = 0; i < d; i++)
//     {
//         arr[n-d+i]=temp[i];
//     }
    
//     //display
//      for(int i=0;i<n;i++)
//     cout<<arr[i]<<" ";
// }

// write function to reverse an array
void reverseArray(vector<int> &arr, int a, int b){
    while(a<b){
        swap(arr[a], arr[b]);
        a++;
        b--;
    }
        // for(int i=0;i<arr.size();i++)
        // cout<<arr[i]<<" ";
        // cout<<endl;
}



void rotateArray(vector<int> &arr,int n, int d){
    d=d%n;
    reverseArray(arr,0,d-1);
    reverseArray(arr,d,n-1);
    reverseArray(arr,0,n-1);

    ////  stl function Only for int array type:
    // reverse(arr,arr+d);
    // reverse(arr+d,arr+n);
    // reverse(arr,arr+n);

    //display
     for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
  vector<int> arr={1,2,3,4,5,6,7,8,9};
  int n=arr.size();
  int d;
  cout<<"enter d"<<endl;
  cin>>d;
  rotateArray(arr,n,d);
  
}

