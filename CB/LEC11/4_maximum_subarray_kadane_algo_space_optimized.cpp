#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySumUsingKadane(int arr[], int n){
    int x;
    x = arr[0];
    int maxSoFar = x;

    for(int i = 0; i<=n-1; i++)
    {
        x = max(x+arr[i],arr[i]);
        maxSoFar = max(maxSoFar,x);
    }
    return maxSoFar;
}

int main()
{
    int arr[] = {1};
    int n = 1;
    cout << maxSubArraySumUsingKadane(arr,n);
}

