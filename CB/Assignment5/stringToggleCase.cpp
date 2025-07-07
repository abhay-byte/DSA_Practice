#include <iostream>
#include <string>
using namespace std;

string toggleCase(const string& s) {
    string result = s;

    for (char& ch : result) {
        if (isupper(ch)) {
            ch = tolower(ch);
        } else if (islower(ch)) {
            ch = toupper(ch);
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    if (s.length() < 1 || s.length() > 1000) {
        cout << "Invalid string length" << endl;
        return 0;
    }

    cout << toggleCase(s) << endl;

    return 0;
}
