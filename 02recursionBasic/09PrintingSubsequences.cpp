#include<bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int>&list, vector<int>&arr,int n ){
    if(ind==n){
        for(auto it:arr){
            cout<<it<<" ";
        }
        if(arr.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    //pick
    arr.push_back(list[ind]);
    printF(ind+1,list,arr,3);
    //not pick
    arr.pop_back();
    printF(ind+1,list,arr,3);

}

int main()
{
 vector<int> list={3,1,2};
 vector<int> arr={};
 printF(0,list,arr,3);
 return 0;
}

//tc- O((2^n) x n) 
//sc-O(n)