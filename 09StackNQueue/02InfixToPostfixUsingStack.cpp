#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";

        for (auto i : s) {
            if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
                ans += i;
            }
            else if (i == '(') {
                st.push(i);
            }
            else if (i == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
            }
            else { // Operator case
                while (!st.empty() && priority(i) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(i);
            }
        }

        // Pop remaining operators in the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string expression = "A*(B+C)/D";
    cout << "Postfix Expression: " << sol.infixToPostfix(expression) << endl;
    return 0;
}

//tc: O(N)+O(N)
//sc: O(N)+O(N)