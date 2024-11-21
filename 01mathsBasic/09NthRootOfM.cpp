#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
	    int low=0;
	    int high=m;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(pow(mid,n)==m) return mid;
	        else if(pow(mid,n)<m) low=mid+1;
	        else high=mid-1;
	        
	    }
	    return -1;
}  

int main()
{
 cout<<NthRoot(2,9);   
 return 0;
}