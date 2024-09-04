#include <bits/stdc++.h>
using namespace std;

//Brute -memory limit exceeds 
 /*    bool isPalindrome(string s) {
        string reversedStr="";
        string originalStr="";
        for(char c : s){
            if(isalnum(c)){
                c=tolower(c);
                reversedStr=c +reversedStr;  
                originalStr=originalStr +c;                  

            }       
        }
  
        if(reversedStr==originalStr)return true;
        else return false;

    } */

//Optimal - 2 pointer
bool isPalindrome(string s) {
    int left=0, right=s.size()-1;
    while(left<right){
        while(left<right && !isalnum(s[left])) left++;
        while(left<right && !isalnum(s[right])) right--;
        if(tolower(s[left])!=tolower(s[right]))return false;
        left++;
        right--;
    }
    return true;
}


int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}