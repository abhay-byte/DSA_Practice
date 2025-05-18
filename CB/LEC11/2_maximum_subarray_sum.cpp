#include <iostream>
#include <climits>
using namespace std;
int maxSubArraySum(int arr[], int n)
{
    int maxSoFar = INT_MIN;
    int psum[101] = {}; 
    psum[0] = 0; // Initialize the first prefix sum to 0
    for(int i = 1; i <= n; i++)
    {
        psum[i] = psum[i-1] + arr[i-1];
    }

    for(int i = 0; i <= n-1; i++)
    {
        for(int j = i; j <= n-1; j++)
        {
            int sum = psum[j+1] - psum[i];
            maxSoFar = max(maxSoFar, sum);
        }
    }
    return maxSoFar;
}
int main()
{
    int arr[] = {10,20,30,40,-100};
    int n = 5;
    cout << maxSubArraySum(arr,n);
}

