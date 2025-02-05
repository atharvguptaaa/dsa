// Count the number of words starting and ending with a vowel in given query ranges
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);// Prefix sum array to store cumulative count of valid words
        // Precompute prefix sums
        for (int i = 0; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        vector<int> res;
        // Answer queries in O(1) time using the prefix sum array
        for (auto query : queries) {
            int count = prefixSum[query[1] + 1] - prefixSum[query[0]];
            res.push_back(count);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"apple", "orange", "banana", "umbrella", "ice"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {0, 4}};
    
    vector<int> result = sol.vowelStrings(words, queries);
    
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}
