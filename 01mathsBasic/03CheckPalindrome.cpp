#include<bits/stdc++.h>
using namespace std;

//Approach 1: reversing the whole number
/*    bool isPalindrome(int x) {
        if(x<0) return false;
        long long reversed=0;
        long long temp=x;
        while(temp!=0){
        int digit=temp%10;
        reversed=reversed*10+digit;
        temp=temp/10;
        }
        return (reversed==x);
    } */

//Optimized Approach -reversing second half
bool isPalindrome(int x) {
        if(x<0||(x!=0&&x%10==0)) return false; //numbers with 0 at end cant be palindrome
        int reversed=0;
        while(x>reversed){ // loop stops when reversed equals or crosses x
        reversed=reversed*10+x%10;
        x/=10;
        }
        return (x==reversed) || (x==reversed/10);// for even and odd
    }

int main()
{
  bool yORn= isPalindrome(131);
  cout<<yORn;
 
}
