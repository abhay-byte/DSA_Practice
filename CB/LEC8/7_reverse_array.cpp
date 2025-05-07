#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    //swap() will be used.
    int size = sizeof(arr)/sizeof(int);
    int left = 0;
    int right = size-1; //Two Pointer Approach
    while(left<right) {
        swap(arr[left], arr[right]);
        left++; right--;
    }
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    

    return 0;
}