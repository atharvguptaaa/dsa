#include<bits/stdc++.h>
using namespace std;
vector<int> v={};
int printDivisors(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            // cout<<i<<" ";
            if((n/i)!=i){
                // cout<<n/i<<" ";
                v.push_back(n/i);
            }
        }
}
sort(v.begin(),v.end());
for(auto i:v){
    cout<<i<<" ";
    }
return 0;
  }


int main()
{
 printDivisors(64);
}