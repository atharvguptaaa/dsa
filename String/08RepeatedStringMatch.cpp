/* Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.*/ #include<iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// O(m*n) approach
/*     int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;
        int repeat = 1;                                                   
        string temp = a;
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }
        if (temp.find(b) != string::npos) return repeat;
        temp += a;
        repeat++;
        if (temp.find(b) != string::npos) return repeat;
        return -1;
    } */

vector<int> calcLPSArray(string s)
{
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;
    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return lps;
}

bool findByKMP(vector<int> &lps, string b, string temp)
{
    int i = 0, j = 0;
    while (i < temp.size())
    {
        if (temp[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
        if (j == b.size())
            return true;
    }
    return false;
}

int repeatedStringMatch(string a, string b)
{
    if (a == b)  return 1;
    int repeat = 1;
    string temp = a;
    while (temp.size() < b.size())
    {
        temp += a;
        repeat++;
    }

    vector<int> lps = calcLPSArray(b);

    if (findByKMP(lps, b, temp)) return repeat;
    temp += a;
    repeat++;
    if (findByKMP(lps, b, temp)) return repeat;

    return -1;
}

int main()
{
    string a = "abcd";
    string b = "cdabcdab";
    int result = repeatedStringMatch(a, b);
    cout << result << endl;
    return 0;
}
