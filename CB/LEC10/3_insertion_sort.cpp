#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n)
{
    for(int i = 1; i <= n-1; i++)
    {
        int key = arr[i]; //insert key to current position in sorted part of array
        int j = i-1;
        while(j>=0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {1,3,6,2,54,21,67,8};
    int n = sizeof(arr)/sizeof(int);

    InsertionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0 ;

}