#include<bits/stdc++.h>
using namespace std;
#include <string>

 int getLucky(string s, int k) {
        string strSum="";
        int sum=0;
        for(char c:s){
            strSum+=to_string(c-96);
        }

        while(k>0){
            sum=0;
            for(char c:strSum){
                sum+=c-'0';
        }
        strSum=to_string(sum);
        k--;
        }
        
        return sum;
    }

int main()
{
 string s="leetcode";
 int k=2;
 cout<<getLucky(s,k);
 return 0;
}