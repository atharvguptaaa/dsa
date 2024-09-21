#include<bits/stdc++.h>
using namespace std;
/* USING KMP ALGO */
//LPS - Longest Prefix that is also a Suffix
string calcLPS(string s) {
    int n = s.size();
    if (n == 0) return "";
    
    vector<int> ans(n, 0);// Vector to store the length of the longest prefix-suffix
    int pre = 0, suf = 1;
    
    while (suf < n) {
        if (s[pre] == s[suf]) { // pre and suf match
            ans[suf] = pre + 1; 
            pre++;
            suf++;
        } else {      // mismatch
            if (pre == 0) {
                ans[suf] = 0;
                suf++;
            } else {
                pre = ans[pre - 1]; //as per KMP algo
            }
        }
    }
    return s.substr(0, pre); //at the end pre represents the length of the longest prefix which is also suffix
}

int main() {
    string test = "abcabbbbbabcab";
    cout << "Longest prefix which is also suffix: " << calcLPS(test) << endl;
    return 0;
}
