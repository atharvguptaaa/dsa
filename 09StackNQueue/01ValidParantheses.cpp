#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (auto it : s) {
            if (it == '(' || it == '[' || it == '{')
                st.push(it);
            else {
                if (st.empty()) return false;
                if ((st.top() == '(' && it == ')') ||
                    (st.top() == '{' && it == '}') ||
                    (st.top() == '[' && it == ']'))
                    st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    
    // Made-up input
    string input = "{[()]}";  // You can change this input to test different cases

    bool result = solution.isValid(input);
    
    cout << (result ? "Valid" : "Invalid") << endl;
    
    return 0;
}
