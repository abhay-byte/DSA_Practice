#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    s += " World";             // Concatenate
    s.append("!!!");           // Append
    cout << "s: " << s << endl;

    cout << "Length: " << s.length() << endl;
    cout << "First: " << s.front() << ", Last: " << s.back() << endl;

    s.insert(5, " Amazing");   // Insert
    cout << "After Insert: " << s << endl;

    s.replace(6, 7, "Cool");   // Replace
    cout << "After Replace: " << s << endl;

    s.erase(5, 5);             // Erase
    cout << "After Erase: " << s << endl;

    string sub = s.substr(0, 5);  // Substring
    cout << "Substring: " << sub << endl;

    int pos = s.find("World");    // Find
    if (pos != string::npos) {
        cout << "'World' found at: " << pos << endl;
    }

    cout << "Using c_str(): " << s.c_str() << endl;

    std::string str = "Hello";

    // Method 1: Index-based
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i] << " ";
    }

    // Method 2: Range-based for loop
    for (char ch : str) {
        std::cout << ch << " ";
    }

    // Method 3: Iterator
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
