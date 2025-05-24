#include <iostream>

using namespace std;

//time: n^2.const ~ O(n^2)
//space: O(1)

int sumEqualToTarget(int arr[], int n, int target)
{
    int pairs = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j] == target)
            {
                pairs++;
            }
        }

    }
    return pairs;

}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = 5;

    cout << sumEqualToTarget(arr, n, 40);
}