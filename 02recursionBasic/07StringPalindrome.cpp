#include<bits/stdc++.h>
using namespace std;


bool f(int i,string word){
    int n=word.length();
    if(i>=n/2) return true;
    if(word[i]!=word[n-i-1])
    return false;
    return f(i+1,word);
}
 
int main()
{
 string InputString;
 cout<<"Enter a word- ";
 cin>>InputString;
 cout << (f(0,InputString) ? "true" : "false");

}
