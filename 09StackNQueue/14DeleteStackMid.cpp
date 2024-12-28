// Program to delete the middle element of a stack without using any additional data structures.

#include <iostream>
#include <stack>
using namespace std;

void delStackMid(stack<int>& st, int n, int cur) {
    if (cur == n / 2) {
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();   //pop from last

    delStackMid(st, n, cur + 1);

    st.push(top); //after middle removal,push till end
}

void deleteMid(stack<int>& s) {
    int n = s.size();
    delStackMid(s, n, 0);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMid(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
