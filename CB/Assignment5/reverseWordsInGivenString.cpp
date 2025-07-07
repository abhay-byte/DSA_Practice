#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseDotWords(const string& s) {
    vector<string> words;
    string word, result;

    // Split the string by dot
    for (char ch : s) {
        if (ch == '.') {
            words.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    words.push_back(word); // push the last word

    // Reverse the words
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) {
            result += '.';
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    cout << reverseDotWords(s) << endl;

    return 0;
}
