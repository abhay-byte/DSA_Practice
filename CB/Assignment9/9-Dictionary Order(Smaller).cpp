#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(string &s, int index, vector<string> &result) {
    // Base case: if we've fixed all positions, store permutation
    if (index == s.size()) {
        result.push_back(s);
        return;
    }

    // Recursion case: swap each character into current index
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        generatePermutations(s, index + 1, result);
        swap(s[index], s[i]); // backtrack
    }
}

int main() {
    string input;
    cin >> input;

    vector<string> perms;
    string str = input;
    generatePermutations(str, 0, perms);

    // Sort permutations lexicographically
    sort(perms.begin(), perms.end());

    // Print only those lexicographically less than input
    for (auto &word : perms) {
        if (word < input) {
            cout << word << endl;
        }
    }

    return 0;
}
