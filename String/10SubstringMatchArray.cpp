// Find words that are substrings of other words in the array
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

       vector<vector<int>> makeLpsList(vector<string>& words){
        int n=words.size();
        vector<vector<int>>lpsList(n);
        for(int i=0;i<n;i++){
            string s=words[i];
            int pre=0;
            int suf=1;
            int m=s.size();
            vector<int>lps(m,0);
            while(suf<m){
                //match
                if(s[suf]==s[pre]){
                    lps[suf]=pre+1;
                    pre++;
                    suf++;
                }
                //mismatch
                else{
                    if(pre==0){
                        lps[suf]=0;
                        suf++;
                    }
                    else{
                        pre=lps[pre-1];
                    }
                }
            }
            lpsList[i]=lps;
        }
        return lpsList;

    }

    bool stringMatcher(string a, string b, vector<int> lps)
    {
        int length_a=a.size();
        int length_b=b.size();
        int i=0,j=0;
        while(i<length_b){
            if(a[j]==b[i]){
                i++;j++;
            }
            else{
                if(j>0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
                if(j==length_a){
                    return true;
                } 
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        vector<vector<int>> lpsList =makeLpsList(words);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(stringMatcher(words[i],words[j],lpsList[i])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    } 

/*     vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    } */
};

int main() {
    vector<string> words = {"mass", "as", "hero", "superhero"};
    Solution sol;
    vector<string> result = sol.stringMatching(words);
    
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
