#include<bits/stdc++.h>
using namespace std;
#include <string>

char nextGreatestLetter(vector<char>& letters, char target) {
        int t=target;
        cout<<t;
        int ans=letters[0];
        for(int i=1;i<letters.size();i++){
            int l=letters[i];
            cout<<l<<endl;
            if(l>t){
                ans=l;
                ans=min(ans,l);
                cout<<"ans"<<ans<<endl;
            }
        }
        return (char)ans;

    }

int main()
{
 vector<char> letters={'c','f','j'};
 cout<<nextGreatestLetter(letters,'c');
 return 0;
}