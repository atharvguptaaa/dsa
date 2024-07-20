

#include <bits/stdc++.h>
using namespace std;
// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

/*  // Brute Force Approach: 
int missingNumber(vector<int> &a, int N)
{
 // Outer loop that runs from 1 to N: Correct array
    for (int i = 1; i <= N; i++) {

                // flag variable to check
                //if an element exists
                int flag = 0;

                //Search the element using linear search: Given array
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] == i) {

                        // i is present in the array:
                        flag = 1;
                        break;
                    }
                }
                // if element is not in array then the if stmt in second loop wont execute and flag will be 0
                //  i th element in correct array is the missing one


                if (flag == 0) return i;
            }

            // The following line will never execute.
            // It is just to avoid warnings.
                return -1;
        }    //tc : O(n x n) */

/* //Better approach using hash map
int missingNumber(vector<int> &a, int N)
{
    int hash[N+1]={};

    for (int i=1;i<=N;i++){
        hash[i]=0;
    }
    for(int i=0;i<N-1;i++){
        hash[a[i]]=1;
    }
    for(int i=1;i<=N;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}
     //tc : O(n)    */

/* //Optimal approach using sum
int missingNumber(vector<int> &a, int N)
{
    int sum = (N * (N + 1)) / 2;
    for (int i = 0; i < N - 1; i++)
    {
        sum -= a[i];
    }
    return sum;
}
     //tc : O(n)     */

/* //Optimal approach using XOR
                                    /*    Theory
                                    XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
                                    XOR of array elements i.e. xor2 = (1^2^4^5)
                                    XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
                                                = (1^1)^(2^2)^(3)^(4^4)^(5^5)
                                                = 0^0^3^0^0 = 0^3 = 3.
                                                The missing number is 3. */
int missingNumber(vector<int> a, int N){
    int xor1=0,xor2=0;
    for(int i=0;i<N-1;i++){
        xor2=xor2^a[i]; //xor of all array elements
        xor1=xor1^(i+1);// xor of all numbers from 1 to N-1
    }
        xor1=xor1^N;  //xor of 1to N
        return xor1^xor2;

    }   //tc : O(n)

// Driver Code
int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}