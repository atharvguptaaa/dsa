#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postToInfix(string exp) {
    stack<string> st;
    for (auto i : exp) {
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
            st.push(string(1, i)); // Convert char to string and push
        }
        else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
              
            string con = '(' + s2 + i + s1 + ')';
            st.push(con); 
        }
    }
    return st.top(); 
}

int main() {
    string expression = "AB+C*"; 
    cout << "Infix Expression: " << postToInfix(expression) << endl;
    return 0;
}

//tc-O(N) +O(N) --> 1)outer loop 2) addition of two strings may take O(s1+s2) so wc O(N)
//sc-O(N) 