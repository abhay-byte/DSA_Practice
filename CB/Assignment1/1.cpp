#include <iostream>
using namespace std;

int main() {
	int N = 7;
	cin >> N;
    for (int i = 1; i <= N; i++) {
        // Print numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        // Print stars to complete 7 characters in the row
        for (int k = 1; k <= N - i; k++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
