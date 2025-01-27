//1422. Given a binary string, find the maximum score obtained by splitting the string into two non-empty parts.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int oneCount = 0;
        for (char c : s) {
            if (c == '1') oneCount++;
        }
        int zero = 0;
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s.at(i) == '0') {
                zero++;
            } else {
                oneCount--;
            }
            res = max(res, zero + oneCount);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "011101"; // Hardcoded input string
    cout << sol.maxScore(s) << endl;
    return 0;
}
