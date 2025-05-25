#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dnfSort(vector<int> &arr)
{
    int n = arr.size();

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        { // put arr[mid] to region of zeros
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        { // put arr[mid] to region of ones
            mid++;
        }
        else
        {
            // arr[mid] == 2 // put arr[mid] to region of twos
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{

    return 0;
}
