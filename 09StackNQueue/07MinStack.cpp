#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    // Using Pairs approach
    /* stack<pair<int ,int>> st;
    MinStack() {
       
    }
    
    void push(int val) {
        if (st.empty())
        st.push({val,val});
        else{
            int p2=st.top().second;
            st.push({val,(val<p2)?val:p2});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
            return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    } */

//Formula approach
    long long min;
    stack<long long> st;

    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()){
            st.push(val);
            min=val;
        }
        else{
            if(val > min){
                st.push(val);
            }
            else{
                st.push(2 * ((long long)val) - min);
                min = val;
            }
        }
    }
    
    void pop() {
         long long x = st.top();
         st.pop();
         if(x < min){
            min = 2 * min - x;
         }
    }
    
    int top() {
        long long x = st.top();
        if(x < min){
            return (int)min;
        }
        return (int)x;
    }
    
    int getMin() {
        return (int)min;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(5);
    obj->push(2);
    cout << "Top: " << obj->top() << endl;  // Expected output: 2
    cout << "Min: " << obj->getMin() << endl;  // Expected output: 2
    obj->pop();
    cout << "Top: " << obj->top() << endl;  // Expected output: 5
    cout << "Min: " << obj->getMin() << endl;  // Expected output: 3
    obj->push(1);
    cout << "Top: " << obj->top() << endl;  // Expected output: 1
    cout << "Min: " << obj->getMin() << endl;  // Expected output: 1
    return 0;
}
