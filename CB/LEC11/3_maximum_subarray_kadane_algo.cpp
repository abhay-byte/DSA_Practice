#include <iostream>
#include <climits>
using namespace std;

//t:O(n) s:0(n)

int maxSubArraySumUsingKadane(int arr[], int n)
{
    int arr_x[100];
    arr_x[0] = arr[0];
    int maxSoFar = arr_x[0];
    for(int i = 0; i<=n-1; i++)
    {
        arr_x[i] = max(arr_x[i-1]+arr[i],arr[i]);
        maxSoFar = max(maxSoFar,arr_x[i]);
    }
    return maxSoFar;
}


int main()
{
    int arr[] = {1};
    int n = 1;

    cout << maxSubArraySumUsingKadane(arr,n);

}