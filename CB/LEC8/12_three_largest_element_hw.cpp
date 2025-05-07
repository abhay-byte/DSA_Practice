#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,4,6,2,8,1,8,7};
    int n = 8;

    // Initialize top 3 values
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }

    int sum = first+second+third;
    cout << sum;
    return 0;
}
