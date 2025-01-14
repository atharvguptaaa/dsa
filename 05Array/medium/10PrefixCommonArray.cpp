// Problem Statement: Given two arrays A and B, find the prefix common array where each index i stores the count of elements common to A and B up to index i.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1, 0);
        vector<int> result(n);
        int common = 0;
        for (int i = 0; i < n; i++) {
            count[A[i]]++;
            if (count[A[i]] == 2) common++;
            count[B[i]]++;
            if (count[B[i]] == 2) common++;
            result[i] = common;
        }
        return result;
    }
};

int main() {
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    Solution sol;
    vector<int> result = sol.findThePrefixCommonArray(A, B);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
