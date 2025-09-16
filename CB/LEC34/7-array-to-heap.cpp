#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// [HW] try to implement heapify iterative

void heapify(vector<int> &v, int n, int i)
{
    // fies the property of heap at the node corr, to idx i
    int maxIdx = i;

    int leftChildIdx = 2 * i + 1;
    if (v.size() > leftChildIdx && v[leftChildIdx] > v[maxIdx])
    {
        maxIdx = leftChildIdx;
    }

    int rightChildIdx = 2 * i + 2;
    if (v.size() > rightChildIdx && v[rightChildIdx] > v[maxIdx])
    {
        maxIdx = rightChildIdx;
    }

    if (maxIdx != i)
    {
        // base case is automatic taken
        swap(v[i], v[maxIdx]);
        heapify(v, n, maxIdx);
    }
}

int main()
{
    vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
    int n = v.size();

    // time: O(n)

    // iterate form leaf to root and invoke heapify
    // to transform the array into a heap

    for (int i = n - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    for (int i : v)
    {
        cout << i << " ";
    }
}