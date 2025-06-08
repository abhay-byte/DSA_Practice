/*


Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.
Input Format

Constraints

0 < N1 < 1000000000
0 < N2 < 1000000000
Output Format

Sample Input

4 
6

Sample Output

12

Explanation

The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.

*/

#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long n1, long long n2) {
    return (n1 / gcd(n1, n2)) * n2;
}

int main() {
    long long N1, N2;
    cin >> N1 >> N2;

    if (N1 <= 0 || N1 >= 1000000000 || N2 <= 0 || N2 >= 1000000000) {
        cerr << "Invalid input. Please enter numbers in the range 0 < N < 1000000000." << endl;
        return 1;
    }

    cout << lcm(N1, N2) << endl;

    return 0;
}
