// Program to find the length of the longest substring without repeating characters

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        unordered_map<char, int> charMap;
        int l = 0;
        int r = 0;
        while (r < n) {
            if (charMap.find(s[r]) != charMap.end() && charMap[s[r]] >= l) {
                l = charMap[s[r]] + 1;
            }
            maxLen = max(maxLen, r - l + 1);
            charMap[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

int main() {
    string s = "abcabcbb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}
