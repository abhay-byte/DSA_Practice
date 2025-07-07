#include <iostream>
#include <string>
using namespace std;

void splitCamelCaseWords(const string& s) {
    string word;

    for (char ch : s) {
        if (isupper(ch) && !word.empty()) {
            cout << word << endl;
            word = ch; // start new word with the capital letter
        } else {
            word += ch;
        }
    }

    // Print the last word
    if (!word.empty()) {
        cout << word << endl;
    }
}

int main() {
    string s;
    cin >> s;

    splitCamelCaseWords(s);

    return 0;
}
