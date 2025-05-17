#include <iostream>

using namespace std;

int BinarySearch(int arr[], int n, int t)
{
    int s = 0;
    int e = n-1;


    while (s<=e)
    {
        int m = (s+e)/2;
        if(arr[m]==t)
        {
            return m;
        }
        else if (t > arr[m])
        {
            s = m+1;
        }
        else{
            e = m-1;

        }
    }
    return -1; //target not present

}

int main()
{
    int arr[] = {1,3,6,2,54,21,67,8};
    int target = 3;
    int n = sizeof(arr)/sizeof(int);

    cout << endl;
    cout << BinarySearch(arr,n, target);

    cout << endl;

    return 0 ;

}