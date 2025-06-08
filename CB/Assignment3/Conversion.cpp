/*


Take sb (source number system base), db (destination number system base) and sn (number in source format). Write a function that converts sn to its counterpart in destination number system. Print the value returned.
Input Format

Constraints

0 < N <= 1000000000
sb and db <= 10
Output Format

Sample Input

8
2 
33

Sample Output

11011

Explanation

All input output is as integers and in separate lines.

*/

#include <iostream>
#include <cmath>
using namespace std;

int toDecimal(int sb, int sn) {
    int decimalValue = 0;
    int power = 0;

    while (sn > 0) {
        int digit = sn % 10;
        decimalValue += digit * pow(sb, power); 
        sn /= 10; 
        power++;
    }

    return decimalValue;
}

int fromDecimal(int db, int decimalValue) {
    int convertedValue = 0;
    int place = 1;

    while (decimalValue > 0) {
        int digit = decimalValue % db; 
        convertedValue += digit * place; 
        decimalValue /= db; 
        place *= 10;
    }

    return convertedValue;
}

int main() {
    int sb, db, sn;
    cin >> sb >> db >> sn;

    if (sb <= 0 || db <= 0 || sb > 10 || db > 10 || sn <= 0 || sn > 1000000000) {
        cerr << "Invalid input. Ensure 0 < sb, db <= 10 and 0 < sn <= 1000000000." << endl;
        return 1;
    }

    int decimalValue = toDecimal(sb, sn); 
    int result = fromDecimal(db, decimalValue); 

    cout << result << endl;

    return 0;
}
