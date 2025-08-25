#include <iostream>
#include <string>
using namespace std;

void printAsciiSubsequences(string input, string output) {
    // Base case
    if (input.empty()) {
        cout << output << " ";
        return;
    }

    char ch = input[0];
    string rest = input.substr(1);

    // Recursion case 1: Exclude the character
    printAsciiSubsequences(rest, output);

    // Recursion case 2: Include the character as it is
    printAsciiSubsequences(rest, output + ch);

    // Recursion case 3: Include ASCII code of character
    printAsciiSubsequences(rest, output + to_string((int)ch));
}

int countAsciiSubsequences(string input) {
    // Base case
    if (input.empty()) {
        return 1; // empty string has one subsequence: ""
    }

    // Recursion case: 3 choices for each character
    return 3 * countAsciiSubsequences(input.substr(1));
}

int main() {
    string str;
    cin >> str;

    printAsciiSubsequences(str, "");
    cout << endl;

    cout << countAsciiSubsequences(str) << endl;

    return 0;
}
