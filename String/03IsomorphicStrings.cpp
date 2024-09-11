#include<bits/stdc++.h>
using namespace std;

//brute using map and set;
/*     bool isIsomorphic(string s, string t) {
        map<char,char> mpp;
        set<char> st;
        if(s.size()!=t.size()) return false;
        int i=0;
        while(i<s.size()){
             if(mpp.find(s[i])!=mpp.end()){
                if(t[i]!=mpp[s[i]]) return false;
             }
            else{
               if(st.find(t[i])!=st.end()) return false;
            mpp[s[i]]=t[i];
            st.insert(t[i]);
            }
            i++;
        }
        return true;
    } */

//optimized using two arrays as maps to store last seen position(assumed s==t in length)
    bool isIsomorphic(string s, string t) {
        int mapS[256]={0};  //arr size 256 as ascii val for letters range 0-255
        int mapT[256]={0};

        for(int i=0;i<s.size();i++){
            if(mapS[s[i]]!=mapT[t[i]]) return false; //compare last seen positions in both maps

            mapS[s[i]]=i+1;  //i+1 as initialized val is 0
            mapT[t[i]]=i+1;

        }
        return true;

    }

int main()
{
 string s="paper";
 string t="title";
 if(isIsomorphic(s,t))
 cout<<"True";
 else cout<<"False";
 return 0;
}