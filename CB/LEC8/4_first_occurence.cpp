#include<iostream>
#include<cstring>
using namespace std;

int main()
{

    int arr[100] = {1,2,3,4,5}; //n<=100 constrain
    int size = sizeof(arr)/sizeof(int);
    int index = -1;
    int target = 1;

    //linear search
    //worst case will be when target not found, O(n)

    for(int j=0; j<size ;j++)
    {
        if(arr[j]==target)
        {
            index = j;
            cout << "\nFirst Occurence is at index: " << j;
            break;
        }
    }
    if (index==-1)
    {
        cout << "\nTarget not found.";
    }
    return 0;
    

}