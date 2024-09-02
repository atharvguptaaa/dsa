#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N = 123;
    int num = N;
    int reverse = 0;
    while(N!=0)
    {
        int digit = N%10;
        if(reverse>INT_MAX/10 || reverse<INT_MIN/10) return 0;
        reverse = reverse*10+digit;
        N = N/10;
    }
    cout<<reverse;
}
