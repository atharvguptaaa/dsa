// Program to find the previous smaller element for each element in an array.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) { 
    vector<int> pse(A.size(), -1);
    stack<int> st;
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && A[i] <= st.top()) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(A[i]);
    }
    return pse;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8}; // hardcoded array
    vector<int> result = prevSmaller(A);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
