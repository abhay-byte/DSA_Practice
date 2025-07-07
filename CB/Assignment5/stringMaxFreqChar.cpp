#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char mostFrequentChar(const string& s) {
    unordered_map<char, int> freq;

    // Count frequency of each character (case-sensitive)
    for (char ch : s) {
        freq[ch]++;
    }

    // Find the character with the maximum frequency
    char maxChar = s[0];
    int maxFreq = freq[maxChar];

    for (auto& entry : freq) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            maxChar = entry.first;
        }
    }

    return maxChar;
}

int main() {
    string s;
    cin >> s;

    cout << mostFrequentChar(s) << endl;

    return 0;
}
