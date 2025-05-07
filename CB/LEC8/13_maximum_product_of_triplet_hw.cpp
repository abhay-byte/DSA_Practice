#include <iostream>
#include <algorithm> // for sort
using namespace std;

int main() {

    int arr[] = {5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);  // sorts in ascending order
    int i = max(arr[0]*arr[1]*arr[n-1],arr[n-1]*arr[n-2]*arr[n-3]);
    cout << i;
    
}
