#include <iostream>
using namespace std;

string removeConsecutiveDuplicates(string s) {
    string result;
    for (char ch : s) {
        if (result.empty() || result.back() != ch) {
            result += ch;
        }
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << removeConsecutiveDuplicates(s) << endl;
    return 0;
}
