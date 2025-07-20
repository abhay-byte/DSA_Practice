#include<iostream>
#include<vector>
using namespace std;


bool f(vector<int> arr, int n, int i)
{
    // create a base case
    if(n == 0)
    {
        return 1;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1
    int a = f(arr, n-1, i + 1);
    return arr[i] < arr[i+1] && a;
}

int main()
{
    vector<int> arr = {10,20,100,40,50};

    cout << f(arr, arr.size()-1,0) << endl;
}