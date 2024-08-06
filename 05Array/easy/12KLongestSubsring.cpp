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
/*     int getLongestSubarray(vector<int>& a, long long k) {
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
*/

//Optimal approach -2pointer
int getLongestSubarray(vector<int> &a, long long k){
int left=0;
int right=0;
int sum=a[0];//no. on first index is the sum initially
int maxlen=0;
int n=a.size();
while(right<n){

     while(sum>k&&left<=right){  //if sum exceeds k and checks that atleast one element is in subarray
        sum-=a[left];
        left++;
     }
     if(sum==k){    //when sum matches k calc length
        maxlen=max(maxlen,right-left+1);
     }
     right++;   //move right ahead now 
    if(right<n) sum=sum+a[right];  //check if it doesnt exceed the array and find new sum for next iteration 
}
return maxlen;
}
int main()
{
    vector<int> a = {2, 3,9 , 4,1,2,2, 1};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
