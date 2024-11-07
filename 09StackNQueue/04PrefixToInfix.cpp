#include <iostream>
#include <stack>
#include <string>

using namespace std;

string preToInfix(string pre_exp) {
    stack<string> st;
    for (auto i = pre_exp.rbegin(); i != pre_exp.rend(); ++i) {
        if ((*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z') || (*i >= '0' && *i <= '9')) {
            st.push(string(1, *i));
        }
        else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string con = '(' + s1 + *i + s2 + ')';
            st.push(con); 
        }
    }
    return st.top(); 
}

int main() {
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix expression: " << preToInfix(pre_exp) << endl;  // Expected: ((A-(B/C))*((A/K)-L))
    return 0;
}

//tc-O(N) +O(N) --> 1)outer loop 2) addition of two strings may take O(s1+s2) so wc O(N)
//sc-O(N) 