#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::max

using namespace std;

bool isPossible(const vector<int>& books, int numStudents, int maxPages) {
    int studentsRequired = 1;
    int currentPages = 0;
    for (int pages : books) {
        if (pages > maxPages) {
            return false; // A single book exceeds the limit
        }
        if (currentPages + pages <= maxPages) {
            currentPages += pages;
        } else {
            studentsRequired++;
            currentPages = pages;
        }
    }
    return studentsRequired <= numStudents;
}

int allocateBooks(const vector<int>& books, int numStudents) {
    if (numStudents > books.size()) {
        return -1; // Not possible to allocate
    }

    int left = *max_element(books.begin(), books.end()); // Minimum possible value
    int right = accumulate(books.begin(), books.end(), 0); // Maximum possible value
    int result = right; // Initialize result to the maximum possible value

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(books, numStudents, mid)) {
            result = mid;
            right = mid - 1; // Try to minimize further
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numBooks, numStudents;
        cin >> numBooks >> numStudents;
        vector<int> books(numBooks);
        for (int i = 0; i < numBooks; ++i) {
            cin >> books[i];
        }
        cout << allocateBooks(books, numStudents) << endl;
    }
    return 0;
}
