#include <iostream>
#include <string>
using namespace std;

string compressString(const string& s) {
    string result;
    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    if (s.length() < 1 || s.length() > 1000) {
        cout << "Invalid input length" << endl;
        return 0;
    }

    cout << compressString(s) << endl;

    return 0;
}
