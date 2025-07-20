#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int s, int m, int e)
{
    vector<int> temp{100};
    int i = s;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= e)
    {
        if (arr[i] >= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    arr = temp;
}

void MergeSort(vector<int> &arr, int s, int e)
{
    // create a base case
    if (s == e)
    {
        // sort arr[s..s] / arr [e..e]
        return; // since arr contains 1 element, already sorted
    }

    // recursive case
    // sort [s...e]
    // find mid point
    int m = s + (e - s) / 2;

    // recursively sort two subarrays
    MergeSort(arr, s, m);
    MergeSort(arr, m + 1, e);

    // merge the two sorted subarrays
    Merge(arr, s, m, e);
}

int main()
{
    vector<int> arr = {50, 40, 30, 20, 10};

    MergeSort(arr, 0, arr.size() - 1);

    for (int i : arr)
    {
        cout << i << endl;
    }
}