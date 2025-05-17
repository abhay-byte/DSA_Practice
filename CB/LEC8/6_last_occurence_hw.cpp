#include<iostream>
#include<cstring>
using namespace std;

int main()
{

    int arr[100] = {1,2,3,4,5,1}; //n<=100 constrain
    int size = sizeof(arr)/sizeof(int);
    int no_of_occurences = -1;
    int target = 10;
    for(int j=size-1; j>=0 ;j--)
    {
        if(arr[j]==target)
        {
            no_of_occurences++;
            cout << "\nLast Occurence is at index: " << j;
            break; 
        }
    }
    if (no_of_occurences==-1)
        cout << "\nTarget not found.";
        
    return 0;

}