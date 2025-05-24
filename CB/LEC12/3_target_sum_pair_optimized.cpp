#include <iostream>

using namespace std;

//time: n.const ~ O(n)
//space: O(1)

int sumEqualToTarget(int arr[], int n, int target)
{
    int cnt = 0;
    int i = 0;
    int j = n-1;

    while(i < j)
    {
        int pairSum = arr[i] + arr[j];
        if(pairSum == target)
        {
            i++; j--; cnt++;
        }
        else if(pairSum > target)
        {
            j--;
        }
        else if(pairSum < target)
        {
            i++;
        }
    }
    return cnt;

}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = 5;

    cout << sumEqualToTarget(arr, n, 40);
}