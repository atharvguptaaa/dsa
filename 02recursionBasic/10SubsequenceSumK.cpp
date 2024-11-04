#include<bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int>&list, vector<int>&arr,int n, int sum, int k){
    if(ind==n){
        if(sum==k){
            for(auto it:arr){
            cout<<it<<" ";
        }
        if(arr.size()==0) cout<<"{}";
        cout<<endl;
        
        }
        return;
       
    }
    //pick
    arr.push_back(list[ind]);
    sum+=list[ind];
    printF(ind+1,list,arr,n,sum,k);
    
    //not pick
    arr.pop_back();
    sum-=list[ind];
    printF(ind+1,list,arr,n,sum,k);

}

int main()
{
 vector<int> list={3,1,2};
 vector<int> arr={};
 int sum=0;
 int k=3;
 printF(0,list,arr,list.size(),sum,k);
 return 0;
}
