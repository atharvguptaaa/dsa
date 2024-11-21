/*The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times. */
#include<bits/stdc++.h>
using namespace std;

 int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int hcount=0;
        for(int i =citations.size()-1;i>=0;i--){
            ++hcount;
            if(citations[i]==hcount) return hcount;
            else if(citations[i]<hcount) return --hcount;
        }
        return hcount;
    }

int main()
{
 vector<int> citations ={3,0,6,1,5};
 cout<<hIndex(citations);
 return 0;
}