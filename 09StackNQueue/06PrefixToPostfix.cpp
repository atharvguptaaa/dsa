#include <iostream>
#include <stack>
#include <string>

using namespace std;

string preToPost(string pre_exp) {
    stack<string> st;
    for (auto i = pre_exp.rbegin(); i != pre_exp.rend(); ++i) {
        if ((*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z') || (*i >= '0' && *i <= '9')) {
            st.push(string(1, *i));
        }
        else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string con = s1 + s2 + *i;
            st.push(con); 
        }
    }
    return st.top(); 
}

int main() {
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix expression: " << preToPost(pre_exp) << endl;  // Expected: ABC/-AK/L-*
    return 0;
}
