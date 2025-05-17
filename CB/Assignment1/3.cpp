#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cout << "Invalid input. N must be between 1 and 99." << endl;
        return 0;
    }

    int num = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << "\t";
            num++;
        }
        cout << endl;
    }

    return 0;
}
