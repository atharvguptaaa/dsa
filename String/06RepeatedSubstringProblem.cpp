#include <bits/stdc++.h>
using namespace std;
/* 459. Repeated Substring Pattern
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.*/class Solution {
public:
    int CalcLPS(string s) {
        int n = s.size();
        vector<int> ans(n, 0);
        int pre = 0, suf = 1;
        
        while (suf < n) {
            if (s[pre] == s[suf]) {
                ans[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    ans[suf] = 0;
                    suf++;
                } else {
                    pre = ans[pre - 1];
                }
            }
        }
        return ans.back(); // Return the value at the last index of the LPS array
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int prefix = CalcLPS(s);
        
        if (prefix == 0) return false; // No proper prefix-suffix found
        
        int repeatedSubstrLen = n - prefix; // Length of repeating substring
        return n % repeatedSubstrLen == 0;  // Check if string can be evenly divided
    }
};

int main() {
    Solution solution;
    string s = "abab";

    if (solution.repeatedSubstringPattern(s)) {
        cout << "The string '" << s << "' CAN be constructed by repeating a substring." << endl;
    } else {
        cout << "The string '" << s << "' CANNOT be constructed by repeating a substring." << endl;
    }

    return 0;
}
