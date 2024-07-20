#include <bits/stdc++.h> 
using namespace std;
int findSecondLargest(int n, vector<int> &arr)
{

       int largest =INT_MIN;
	    int slargest =INT_MIN;
	    for(int i=0;i<n;i++){
	        if(arr[i]>largest){
	            slargest=largest;
	            largest=arr[i];
	        }
			else if(arr[i]<largest&&arr[i]>slargest)
			slargest=arr[i];
	        
	    }
		if(slargest==INT_MIN)
		slargest=-1;
	    return slargest;
}

    int main(){
        vector<int> arr={-20,-30,14,20,-1,25,50};

        int n=arr.size();
        cout<<findSecondLargest(n, arr);

    }