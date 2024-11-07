#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postToPre(string post_exp) {
    stack<string> st;
    for (auto i : post_exp) {
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
            st.push(string(1, i)); // Convert char to string and push
        }
        else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string con = i + s2 + s1; // Operator between operands
            st.push(con); 
        }
    }
    return st.top();
}

int main() {
    string post_exp = "AB+C*";
    cout << "Prefix expression: " << postToPre(post_exp) << endl;  // Expected: *+AB C
    return 0;
}
