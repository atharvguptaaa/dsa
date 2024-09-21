/* Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. */
#include <iostream>
#include <string>
using namespace std;

class Solution { 
public:
    bool rotateString(string s, string goal) {
        int slen = s.size();
        int glen = goal.size();
        s = s + s;
        if (glen != slen) return false;
        
        for (int i = 0; i < slen; i++) {
            if (s.substr(i, glen) == goal) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    bool result = solution.rotateString(s, goal);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
