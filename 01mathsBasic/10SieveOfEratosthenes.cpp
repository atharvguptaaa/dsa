#include<bits/stdc++.h>
using namespace std;

// Counts the number of prime numbers strictly less than a given number n
int countPrimes(int n) {
    int count = 0;
    vector<int> sieve(n, 0); //assume all are prime

    for (long long i = 2; i < n; i++) {
        if (sieve[i] == 0) { //if prime(0), increase count
            count++;
            for (long long j = i * i; j < n; j += i) { //and make its multiples non-prime(1)
                sieve[j] = 1;
            }
        }
    }

    return count;
}

//tc -O(n log( log n))   remember


int main() {
    int n = 80;
    int result = countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << result << endl;
    return 0;
}