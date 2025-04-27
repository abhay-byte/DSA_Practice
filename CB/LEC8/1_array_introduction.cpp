#include<iostream>
using namespace std;

int main(){

    int arr[5];
    cout << endl << sizeof(arr) << endl;

    char str[5];
    cout << sizeof(str) << endl;

    double bbr[5];
    cout << sizeof(bbr) << endl;

    //assigning value to arr
    for(int i = 1; i <= 5; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }

    //size of array
    int size = sizeof(arr)/sizeof(int);
    cout << endl << size << endl;

    //array initialization
    int array[5] = {1,2,3,4,5};
    

    return 0;
}
