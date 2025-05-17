#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "N must be greater than 0." << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < i)
                cout << i << " ";
            else
                cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
