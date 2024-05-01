
//PARAMETERISED RECURSION APPROACH:

// #include<bits/stdc++.h>
// using namespace std;

// void SumUptoN(int i,int sum){

//     if(i<1) {
//     cout<<sum;
//     return;}
//     SumUptoN(i-1,i+sum);
// }

// int main()
// {
//     int n;    
//     cout<<"enter n - ";
//     cin>>n;   
//     SumUptoN(n,0);
// }

//FUNCTIONAL RECURSION APPROACH:

#include<bits/stdc++.h>
using namespace std;

int f(int n){
 
  if(n==0) 
  return 0;
  return n+f(n-1);
  
}

int main()
{
    int n;    
    cout<<"enter n - ";
    cin>>n;   
    cout<<f(n);
}