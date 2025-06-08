/*

Take N (number of rows), print the following pattern (for N = 6)
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
Input Format

Constraints

0 < N < 100
Output Format

Sample Input

6

Sample Output

1  
1	1  
1	2	1  
1	3	3	1  
1	4	6	4	1  
1	5	10	10	5	1

Explanation

Each number is separated from other by a tab.

*/

#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k) {
    int res = 1;

    // Calculate C(n, k)
    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cerr << "Invalid input. Ensure 0 < N < 100." << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << binomialCoefficient(i, j);
            if (j < i) cout << "\t"; 
        }
        cout << endl; 
    }

    return 0;
}
