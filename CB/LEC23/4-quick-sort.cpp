#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    //partiton arr[s...e] around the pivot

    int low = s;
    int mid = s;

    int pivot = arr[e];

    while(mid < e){

        if(arr[mid]<pivot)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else
        {
            mid++;
        }

    }

    // put the pivot i.e. arr [e] b/w the left and rigth partition
    swap(arr[low],arr[e]);

   return low;
}

void QuickSort(vector<int> &arr, int s, int e)
{
    // create a base case
    if (s == e)
    {
        // optional
        return;
    }

    if (s > e)
    {
        // mandatory
        return;
    }

    // recursive case

    // f(s,e) = sort arr[s..e] using quick sort algo

    // partition the arr[s..e] around the pivot i.e. arr[e]

    int pidx = partition(arr, s, e);

    // recursively sort the  left and the right partition i.e.
    // arr[s...pidx] and  arr[pidx+1...e]

    QuickSort(arr, s, pidx - 1);
    QuickSort(arr, pidx + 1, e);
}

int main()
{
    vector<int> arr = {60, 50, 20, 10, 40, 30};

    QuickSort(arr, 0, arr.size() - 1);

    for (int i : arr)
    {
        cout << i << endl;
    }
}