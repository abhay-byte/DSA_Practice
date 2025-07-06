#include<iostream>
using namespace std;

// time: O(mxn)

int main()
{
    int mat[][10] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    int n = 3;
    int m = 4;

    int t = 5;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j]==t)
            {
                cout << "Found at index, " << i << " " << j << endl;
            }
        }
    }

    cout << "Not found";
}