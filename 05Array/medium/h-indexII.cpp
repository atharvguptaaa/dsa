//In logn time
#include<bits/stdc++.h>
using namespace std;

 int hIndex(vector<int>& citations) {
         int n=citations.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int hcount=n-mid;
            if(citations[mid]==hcount) return hcount;
            else if(citations[mid]<hcount){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return n-low;
    }

int main()
{
 vector<int> citations ={1,1,4,5};
 cout<<hIndex(citations);
 return 0;
}