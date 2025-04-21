#include <iostream>
#include <stack>
using namespace std;

// Function to display all elements (Traversal)
void traverse(stack<int> s) {
    cout << "Stack elements (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Function to search for an element
bool search(stack<int> s, int key) {
    while (!s.empty()) {
        if (s.top() == key)
            return true;
        s.pop();
    }
    return false;
}

int main() {
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "After pushing 10, 20, 30:" << endl;
    traverse(st);

    // Pop element
    st.pop();
    cout << "After popping one element:" << endl;
    traverse(st);

    // Search for an element
    int key = 20;
    if (search(st, key))
        cout << key << " found in stack." << endl;
    else
        cout << key << " not found in stack." << endl;

    return 0;
}
