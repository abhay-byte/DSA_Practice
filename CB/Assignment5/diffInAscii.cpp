#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string insertAsciiDifferences(const string& s) {
    string result;

    for (int i = 0; i < s.length() - 1; i++) {
        result += s[i];
        int diff = s[i + 1] - s[i];
        result += to_string(diff);
    }

    result += s.back(); // Add the last character

    return result;
}

int main() {
    string s;
    cin >> s;

    if (s.length() < 2 || s.length() > 1000) {
        cout << "Invalid input length" << endl;
        return 0;
    }

    cout << insertAsciiDifferences(s) << endl;

    return 0;
}
