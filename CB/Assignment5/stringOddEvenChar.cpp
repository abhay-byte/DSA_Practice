#include <iostream>
#include <string>
using namespace std;

string transformString(const string& s) {
    string result = s;

    for (int i = 0; i < result.length(); i++) {
        if (i % 2 == 0) {
            // Even index → next ASCII character
            result[i] = result[i] + 1;
        } else {
            // Odd index → previous ASCII character
            result[i] = result[i] - 1;
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

    cout << transformString(s) << endl;

    return 0;
}
