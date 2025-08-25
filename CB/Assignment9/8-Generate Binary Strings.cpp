#include <iostream>
#include <string>
using namespace std;

void generateStrings(string &s, int index) {
    // Base case: if we've reached the end, print the string
    if (index == s.size()) {
        cout << s << " ";
        return;
    }

    // If current char is '?', branch into two possibilities
    if (s[index] == '?') {
        s[index] = '0';
        generateStrings(s, index + 1);

        s[index] = '1';
        generateStrings(s, index + 1);

        // Backtrack to restore original '?'
        s[index] = '?';
    } else {
        // If it's '0' or '1', move to the next character
        generateStrings(s, index + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        generateStrings(s, 0);
        cout << endl;
    }
    return 0;
}
