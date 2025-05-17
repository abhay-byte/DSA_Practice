#include <iostream>

using namespace std;

int LowerBound(int arr[], int n, int t) // find first occurence of t in arr[]
{
    int s = 0;
    int e = n-1;

    int ans = -1; // to track index of occurence of t in arr[]

    while (s<=e)
    {
        // int m = (s+e)/2;
        int m = s + (e-s)/2;
        if(arr[m]==t)
        {
           ans = m;
           e=m-1;
        }
        else if (t > arr[m])
        {
            s = m+1;
        }
        else{
            e = m-1;

        }
    }
   
    return ans; //target not present

}

int main()
{
    int arr[] = {1,2,3,3,3,4,5,5,5,6,6,7};
    int target = 3;
    int n = sizeof(arr)/sizeof(int);

    cout << endl;
    cout << LowerBound(arr,n, target);

    cout << endl;

    return 0 ;

}