/*

Take N as input. Print the sum of its odd placed digits and sum of its even placed digits.
Input Format

Constraints

0 < N <= 1000000000
Output Format

Sample Input

2635

Sample Output

11
5

Explanation

5 is present at 1st position, 3 is present at 2nd position, 6 is present at 3rd position and 2 is present at 4th position.

Sum of odd placed digits on first line. 5 and 6 are placed at odd position. Hence odd place sum is 5+6=11

Sum of even placed digits on second line. 3 and 2 are placed at even position. Hence even place sum is 3+2=5
*/

#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N <= 0 || N > 1000000000) {
        cerr << "Invalid input. Please enter a number between 1 and 1000000000." << endl;
        return 1;
    }

    int oddSum = 0, evenSum = 0;
    int position = 1; 

    while (N > 0) {
        int digit = N % 10; 
        if (position % 2 == 1) {
            oddSum += digit;
        } else { 
            evenSum += digit;
        }
        N /= 10; 
        position++;
    }

    cout << oddSum << endl;
    cout << evenSum << endl;

    return 0;
}
