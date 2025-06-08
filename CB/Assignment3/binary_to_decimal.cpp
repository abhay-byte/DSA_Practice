/*

Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.
Input Format

Constraints

0 < N <= 1000000000
Output Format

Sample Input

101010

Sample Output

42

Explanation

For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.

*/

#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(long long binary) {
    int decimal = 0;
    int p = 0;

    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * pow(2, p); 
        binary /= 10; 
        p++; 
    }

    return decimal;
}

int main() {
    long long N;
    cin >> N;

    if (N <= 0 || N > 1000000000) {
        cerr << "Invalid input. Please enter a binary number between 1 and 1000000000." << endl;
        return 1;
    }

    cout << binaryToDecimal(N) << endl;

    return 0;
}
