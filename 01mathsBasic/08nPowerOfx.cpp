// x^n
#include <bits/stdc++.h>
using namespace std;

//recursive
/* double myPow(double x, int n) {
     if (n == 0) return 1;
     double half = myPow(x, n / 2);
     if (n % 2 == 0) return half * half; //even
     else if (n > 0) return half * half * x; //odd positive
     else return half * half * (1 / x); //odd negative
} */

double pow(double x, int n)
{
    n = abs(n);
    double ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
            n--;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}
double myPow(double x, int n)
{
    double res = pow(x, n);
    if (n < 0)
        return 1 / res;
    return res;
}

int main()
{
    cout << myPow(2, -8);
    return 0;
}