#include <iostream>

using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 1; i <= n-1; i++)
    {
        bool flag = false; //to optimize bubble sort
        for (int j = 1; j < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }

        if(flag == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {1,3,6,2,54,21,67,8};
    int n = sizeof(arr)/sizeof(int);

    BubbleSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0 ;

}