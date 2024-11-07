#include <iostream>
using namespace std;

// Function to find the floor of the square root of a number


/* long long int floorSqrt(long long int n) {
    long long low = 1;
    long long high = n;
    long long ans = 0; 
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (mid * mid <= n) {
            ans = mid; // Possible answer
            low = mid + 1; // Look for a potentially larger answer
        } else {
            high = mid - 1; // Look for a smaller answer
        }
    }
    
    return ans;
} */


long long int floorSqrt(long long int n) {
    long long low = 1;
    long long high = n;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    long long int n = 20; // Hardcoded value
    cout << "Floor square root of " << n << " is: " << floorSqrt(n) << endl;
    return 0;
}
