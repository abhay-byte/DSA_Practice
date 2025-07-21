#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> arr, int n)
{
    // create a base case
    if(n == 0)
    {
        return arr[0];
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1!
    int a = f(arr, n-1);

    return arr[n] + a;
}

int main()
{
    vector<int> arr = {10,20,30,40,50};

    cout << f(arr, arr.size()-1) << endl;
}