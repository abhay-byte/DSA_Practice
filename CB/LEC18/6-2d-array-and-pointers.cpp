#include<iostream>
using namespace std;

int main()
{
    int arr[10][10]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    //arr[0] == &arr[0][0], 
    cout << arr << " " << &arr[0][0] << endl; //same, but +1 increases by one row
    cout << arr[0] << " " << &arr[0][0] << endl; //same, but +1 increases 4 bytes
    cout << arr[1] << " " << &arr[1][0] << " " << arr + 1 << endl;
    cout << arr[2] << " " << &arr[2][0] << " " << arr + 2 << endl;



}