#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxSubArrayProduct(vector<int> arr){
    int n = arr.size();
    int x;
    x = arr[0];
    int maxSoFar = x;

    for(int i = 0; i<=n-1; i++)
    {
        x = max(x*arr[i],arr[i]);
        maxSoFar = max(maxSoFar,x);
    }
    return maxSoFar;
}

int main()
{
    vector<int> arr = {1,3,0,5,6,7,-5,-8,1,3};
    cout << maxSubArrayProduct(arr);
}

