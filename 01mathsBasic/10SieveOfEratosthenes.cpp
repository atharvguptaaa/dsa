#include<bits/stdc++.h>
using namespace std;

// Counts the number of prime numbers strictly less than a given number n
int countPrimes(int n) {
    int count = 0;
    vector<int> sieve(n, 0);

    for (long long i = 2; i < n; i++) {
        if (sieve[i] == 0) {
            count++;
            for (long long j = i * i; j < n; j += i) {
                sieve[j] = 1;
            }
        }
    }

    return count;
}

int main() {
    int n = 80;
    int result = countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << result << endl;
    return 0;
}