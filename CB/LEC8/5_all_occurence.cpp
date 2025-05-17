#include<iostream>
#include<cstring>
using namespace std;

int main()
{

    int arr[100] = {1,2,3,4,5,1}; //n<=100 constrain
    int size = sizeof(arr)/sizeof(int);
    bool is_occurred = false;
    int target = 1;

    //linear search
    //worst case will be when target not found, O(n)

    for(int j=0; j<size ;j++)
    {
        if(arr[j]==target)
        {
            is_occurred=true;
            cout << "\nOccurence is at index: " << j;
           
        }
    }
    if (!is_occurred)
    {
        cout << "\nTarget not found.";
    }
    return 0;
    

}