#include <iostream>
#include <vector>
using namespace std;

char getChar(int n) {
    return 'a' + n - 1;
}

vector<string> getCodes(string str) {
    // Base case
    if (str.length() == 0) {
        return {""};
    }

    vector<string> result;

    // Recursion case: take one digit
    int firstDigit = str[0] - '0';
    if (firstDigit >= 1 && firstDigit <= 9) {
        vector<string> smallOutput1 = getCodes(str.substr(1));
        for (string code : smallOutput1) {
            result.push_back(getChar(firstDigit) + code);
        }
    }

    // Recursion case: take two digits
    if (str.length() >= 2) {
        int firstTwoDigits = stoi(str.substr(0, 2));
        if (firstTwoDigits >= 10 && firstTwoDigits <= 26) {
            vector<string> smallOutput2 = getCodes(str.substr(2));
            for (string code : smallOutput2) {
                result.push_back(getChar(firstTwoDigits) + code);
            }
        }
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    vector<string> codes = getCodes(str);

    cout << "[";
    for (int i = 0; i < codes.size(); i++) {
        cout << codes[i];
        if (i != codes.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
