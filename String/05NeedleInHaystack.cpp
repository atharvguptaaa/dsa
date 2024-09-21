#include <bits/stdc++.h>
using namespace std;
/* 28. Find the Index of the First Occurrence in a String*/
class Solution {
public:
    vector<int> CalcLPSArray(string s) {
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
        return ans;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0;  // Special case: if needle is empty
        if (n < m) return -1;  // If haystack is smaller than needle

        vector<int> lps = CalcLPSArray(needle);
        int i = 0, j = 0;
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = lps[j - 1];  // Move j back to the previous lps position
                } else {
                    i++;  // Move i forward if j is already at 0
                }
            }

            // If the entire needle is found
            if (j == m) {
                return i - j;  // Return the starting index
            }
        }
        return -1;  // If needle is not found
    }
};

int main() {
    Solution solution;
    string haystack = "ababcababcabc";
    string needle = "abcabc";
    
    int result = solution.strStr(haystack, needle);
    cout << "The first occurrence of '" << needle << "' in '" << haystack << "' starts at index: " << result << endl;

    return 0;
}
