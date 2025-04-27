#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    //swap() will be used.
    int size = sizeof(arr)/sizeof(int);
    int i = size-1;
    while (i>0)
    {
        swap(arr[i],arr[i-1]);
        i--;
    }

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}