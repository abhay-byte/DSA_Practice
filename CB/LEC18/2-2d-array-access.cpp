#include<iostream>
using namespace std;

int main()
{
    // declaaration of 2d arrays
    // type name[row][column];
    int arr[3][4] = {{10,15,20,25},
                    {30,35,40,45},
                    {50,55,60,65}};

    //accessing 2d array
    cout << arr[0][1] << endl;
    cout << arr[1][2] << endl;
    cout << arr[2][3] << endl;

    //during initialization of 2d array, specifying no of rows is optional
    //specifying no of columns is required.
    int brr[][4] = {
        {1,2,3,4},
        {2,3,4,5}
    };
    cout << sizeof(brr) << endl;
    cout << brr[0][1] << endl;

    // value not specified it will be zero...(default int value)
    int crr[][4]
    {
        {100,200,300,400},
        {5000,6000}
    };

    cout << crr[1][2] << endl;

    //zero initialized 2d array
    int drr1[][10] = {};
    int drr2[][10] = {0};
    int drr3[][10] = {};

    //loop for 2d array access one loop
    for(int i = 0; i < 3; i++)
    {
        cout << arr[i][0] << " ";
        cout << arr[i][1] << " ";
        cout << arr[i][2] << " ";        
        cout << arr[i][3] << " ";
        cout << endl;
    }

    //loop for 2d array access nested loop
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}