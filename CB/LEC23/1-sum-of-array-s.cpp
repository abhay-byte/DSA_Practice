#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> arr, int n, int i)
{
    // create a base case
    if(i == n-1)
    {
        return arr[n-1];
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1!
    int a = f(arr, n, i+1);

    return arr[i] + a;
}

int main()
{
    vector<int> arr = {10,20,30,40,50};

    cout << f(arr, arr.size(),0) << endl;
}