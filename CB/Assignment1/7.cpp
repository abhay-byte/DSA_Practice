#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cout << "N <= 0 or N >= 100." << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 0) { 
                if (j == 1 || j == i) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
               
                cout << "1";
            }
        }

        cout << endl;
    }

    return 0;
}
