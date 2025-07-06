#include<iostream>
using namespace std;

int main()
{
    int arr[10][10];

    int m = 3; int n = 4;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing row-wise
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
       
        cout << endl;
    }
    // printing column-wise
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i][j] << " ";
        }
       
        cout << endl;
    }


}