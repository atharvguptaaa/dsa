#include <bits/stdc++.h>
using namespace std;


//Brute Force
/* int getLongestSubarray(vector<int>& a, long long k) {
    int n=a.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int sum=0;
         for(int j=i;j<n;j++){
            sum+=a[j]; 
            if(sum==k){
                 maxlen=max(maxlen,j-i+1);
            }
           
         }
    }
    return maxlen;
} */

//Better approach-Hashmap

    int getLongestSubarray(vector<int>& a, long long k) {
        int n=a.size();
        int maxlen=0;
        map<long long, int> prevSums;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            
             sum+=a[i];

            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            
            long long rem=sum-k; //remainder
            
            // checks if remainder is already present in the map
            if(prevSums.find(rem)!=prevSums.end()){
                int len=i-prevSums[rem];  //length of the new subarray(current index - index of  found remainder)
                maxlen=max(maxlen,len);
            }
            //checks if sum is not present in the array already
            if(prevSums.find(sum)==prevSums.end()){
                 prevSums[sum]=i;
            }
        }
        return maxlen;
    }

int main()
{
    vector<int> a = {2, 3, 5,2,2, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
