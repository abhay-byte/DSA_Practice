#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i ++)
    {
        int minIdx = i; //at start of ith pass // assume value at the ith index is the smallest
        for(int j = i+1; j<=n; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[minIdx],arr[i]);
    }
}

int main()
{
    int arr[] = {1,3,6,2,54,21,67,8};
    int n = sizeof(arr)/sizeof(int);

    SelectionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0 ;

}