/*


Given an integer N, print Pascal Triangle upto N rows.
Input Format

Single integer N.
Constraints

N <= 10
Output Format

Print pascal triangle.
Sample Input

4

Sample Output

       1
     1   1
   1   2   1
 1   3   3   1

Explanation

Last row has one " "

*/

#include <iostream>
#include <iomanip>
using namespace std;

void printPascalTriangle(int N) {
    int triangle[10][10] = {0}; 

    for (int i = 0; i < N; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << setw((N - i) * 2) << ""; 

        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int N;

    cin >> N;

    printPascalTriangle(N);


    return 0;
}
