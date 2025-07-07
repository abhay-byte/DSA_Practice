#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char firstNonRepeatingChar(const string& s) {
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char ch : s) {
        freq[ch]++;
    }

    // Find the first character with frequency 1
    for (char ch : s) {
        if (freq[ch] == 1) {
            return ch;
        }
    }

    // If no non-repeating character found
    return -1;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after reading t

    while (t--) {
        string s;
        getline(cin, s); // To read the full line, including spaces
        char result = firstNonRepeatingChar(s);

        if (result == -1) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
